#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Para usar la API de Windows

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    int stock;
    int vendidos;
};

vector<Producto> inventario;
Producto L1 = {5, "Frijol", 7, 1};
Producto L2 = {7, "Arroz", 8, 2};
Producto L3 = {9, "Fideos", 9, 3};
Producto L4 = {6, "Elote", 10, 4};
Producto L5 = {8, "Azucar", 11, 5};





// Cambiar la página de códigos a UTF-8
void setConsoleToUTF8() {
    SetConsoleOutputCP(CP_UTF8);
}

bool siProductoExiste(vector<Producto> inventario, int codigo) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            return true;
        }
    }
    return false;
}

bool siNombreExiste(vector<Producto> inventario, string nombre) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].nombre == nombre) {
            return true;
        }
    }
    return false;
}

void eliminarProductoPorCodigo(vector<Producto>& inventario, int codigo) {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->codigo == codigo) {
            inventario.erase(it);
            cout << "🗑️ Producto con código " << codigo << " eliminado." << endl;
            return;
        }
    }
    cout << "❌ Producto con codigo " << codigo << " no encontrado." << endl;
}

void imprimirInventario(const vector<Producto>& inventario) {
    cout << "📦 Inventario:" << endl;
    for (const auto& producto : inventario) {
        cout << "🔹 Código: " << producto.codigo
             << "       |  🔹 Nombre:  "    <<producto.nombre
             << "            |    🔹 Stock:    " <<producto.stock
             << "          |      🔹 Vendidos:  " <<producto.vendidos << endl;
    }
}

int registrarProducto() {
    Producto nuevoProducto;
    cout << "📋 Ingrese el código del producto (números enteros):" << endl;
    cin >> nuevoProducto.codigo;

    if (siProductoExiste(inventario, nuevoProducto.codigo)) {
        cout << "⚠️ Producto Existente, vuelva a intentarlo" << endl;
        cout << "🔄 Presione ENTER para regresar al menú principal..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
    } else {
        cout << "📝 Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin, nuevoProducto.nombre);

        if (siNombreExiste(inventario, nuevoProducto.nombre)) {
            cout << "⚠️ Nombre de producto existente, vuelva a intentarlo especificando el nombre del producto segun su tipo." << endl;
            cout << "🔄 Presione ENTER para regresar al menu principal" << endl;
            cin.get();
            system("cls");
        } else {
            cout << "📦 Ingrese la cantidad en stock: ";
            cin >> nuevoProducto.stock;
            nuevoProducto.vendidos = 0;
               cout << "✅ Producto registrado exitosamente." << endl;
            cout << "🔄 Presione enter para continuar... ";
            cin.ignore();
            cin.get();
            system("cls");

            inventario.push_back(nuevoProducto);
         
        }
    }

    return 1;
}

int actualizarInventario() {
    int codigo;
    int c;

    cout << "📋 Ingrese el código del producto que desea modificar y presione enter: " << endl;
    
    cin >> codigo;
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            cout << "🔧 Seleccione una opción:" << endl;
            cout << "1️⃣  Modificar Stock" << endl;
            cout << "2️⃣  Modificar Código" << endl;
            cout << "3️⃣  Modificar Nombre" << endl;
            cout << "4️⃣  Modificar Cantidad Vendida" << endl;
            cout << "5️⃣  Modificar Todo" << endl;
            cout << "6️⃣  Eliminar Producto" << endl;
            cin >> c;


            if (c == 1) {
                cout << "📦 La cantidad actual es de " << inventario[i].stock << endl << "Ingrese la nueva cantidad Stock (en números enteros):" << endl;
                cin >> inventario[i].stock;
                cout << "✅ Inventario actualizado exitosamente." << endl;
                 cout << "🔄 Presione enter para continuar... "<< endl;
                 
            } else if (c == 2) {
                int nuevoCodigo;
                cout << "🔢 El código actual es " << inventario[i].codigo << endl << "Ingrese el nuevo código en números enteros: " << endl;
                cin >> nuevoCodigo;
                 cout << "🔄 Presione enter para continuar... "<< endl;
                  cin.ignore();
            cin.get();
            system("cls");

                if (siProductoExiste(inventario, nuevoCodigo)) {
                    cout << "⚠️ No es posible guardar los cambios, el producto con el código " << nuevoCodigo << " ya existe." << endl;
                     cout << "🔄 Presione enter para continuar... "<< endl;
                      cin.ignore();
            cin.get();
            system("cls");

                } else {
                    inventario[i].codigo = nuevoCodigo;
                    cout << "✅ Inventario actualizado exitosamente." << endl;
                                     cout << "🔄 Presione enter para continuar... "<< endl;

                     cin.ignore();
            cin.get();
            system("cls");
                }
            } else if (c == 3) {
                string nuevoNombre;
                cout << "📛 El nombre actual es: " << inventario[i].nombre << endl << "Ingrese el nuevo nombre: " << endl;
                cin.ignore();
                getline(cin, nuevoNombre);

                if (siNombreExiste(inventario, nuevoNombre)) {
                    cout << "⚠️ No es posible guardar los cambios, el producto con el nombre " << nuevoNombre << "vuelva a intentarlo especificando el nombre del producto segun su tipo.." << endl;
                         cout << "🔄 Presione enter para continuar... "<< endl;
                     cin.ignore();
            cin.get();
            system("cls");
                } else {
                    inventario[i].nombre = nuevoNombre;
                    cout << "✅ Inventario actualizado exitosamente." << endl;
                          cout << "🔄 Presione doble enter para continuar... "<< endl;
                     cin.ignore();
            cin.get();
            system("cls");
                }
            } else if (c == 4) {
                cout << "📦 La cantidad actual de ventas de este producto es de: " << inventario[i].vendidos << endl << "Ingrese la nueva cantidad de vendidos: " << endl;
                cin >> inventario[i].vendidos;
                cout << "✅ Inventario actualizado exitosamente." << endl;
             cout << "🔄 Presione enter para continuar... "<< endl;
            cin.ignore();
            cin.get();
            system("cls");
            } else if (c == 5) {
                int nuevoCodigo;
                string nuevoNombre;
                cout << "📦 La cantidad actual de stock de este producto es de: " << inventario[i].stock << endl << "Ingrese la nueva cantidad de stock: " << endl;
                cin >> inventario[i].stock;
                cout << "📛 El Nombre actual de este producto es: " << inventario[i].nombre << endl << "Ingrese el nuevo nombre del producto: " << endl;
                cin.ignore();
                getline(cin, nuevoNombre);
                
                
                cout << "🔢 El Codigo actual es: " << inventario[i].codigo << endl << "Ingrese el nuevo Codigo: " << endl;
                cin >> nuevoCodigo;

                bool codigoDuplicado = (nuevoCodigo != inventario[i].codigo) && siProductoExiste(inventario, nuevoCodigo);
                bool nombreDuplicado = (nuevoNombre != inventario[i].nombre) && siNombreExiste(inventario, nuevoNombre);

                if (codigoDuplicado) {
                    cout << "⚠️ No es posible guardar los cambios, el producto con el codigo " << nuevoCodigo << " ya existe." << endl;
                } else if (nombreDuplicado) {
                    cout << "⚠️ No es posible guardar los cambios, el producto con el nombre " << nuevoNombre << " ya existe." << endl;
               		  cin.ignore();
            cin.get();
            system("cls");	
			    } else {
                    inventario[i].codigo = nuevoCodigo;
                    inventario[i].nombre = nuevoNombre;
                    cout << "📦 La cantidad actual de productos vendidos es: " << inventario[i].vendidos << endl << "Ingrese la nueva cantidad de productos vendidos (en numeros enteros):" << endl;
                    cin >> inventario[i].vendidos;
                    cout << "✅ Inventario actualizado exitosamente." << endl;
                      cin.ignore();
            			cin.get();
            			system("cls");
                    
                }
            } else if (c == 6) {
                eliminarProductoPorCodigo(inventario, codigo);
                                    cout << "Precione enter para continuar..." << endl;

                cin.ignore();
            cin.get();
            system("cls");

            }
            return 1;
        }
    }
    cout << "❌ Producto con codigo " << codigo << " no encontrado presione enter para regresar al menu principal..." << endl;
    cin.ignore();
            cin.get();
            system("cls");
    return 1;
}

int venderProducto() {
    int codigo, cantidadVendida;
    cout << "🔢Ingrese el codigo del producto a vender: ";
    cin >> codigo;
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            cout << "📦 Ingrese la cantidad de elementos que se estan vendiendo: ";
            cin >> cantidadVendida;
            if (cantidadVendida <= inventario[i].stock) {
                inventario[i].vendidos += cantidadVendida;
                inventario[i].stock -= cantidadVendida;
                cout << "✅  Venta realizada exitosamente." << endl;
                return 1;
            } else {
                cout << "❌-----No hay suficiente stock para realizar la venta.!!!!----" << endl;
                return 0;
            }
        }
    }
    cout << "❌ El producto con el código " << codigo << " no se encontró." << endl;
    cout << "Presione ENTER para continuar.." << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return 0;
}

void cargarArticulos() {
    inventario.push_back(L1);
    inventario.push_back(L2);
    inventario.push_back(L3);
    inventario.push_back(L4);
    inventario.push_back(L5);
}

int main() {
    setConsoleToUTF8();
    cargarArticulos();
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    
    cout << "                                   ⌜══════════━┈┈━━┈┈━━┈┈━━┈┈━━━┈┈━━┈┈━━┈┈━━┈┈━━┈┈┈━━┈┈━━┈┈━═══════════⌝        " << endl;
    cout << "                                   ╰╮         ¡Bienvenido al sistema de gestion de inventario!        ╭╯       "  << endl;
    cout << "                                   ⌞══════════━┈┈━━┈┈━━┈┈━━┈┈━━━┈┈━━┈┈━━┈┈━━┈┈━━┈┈┈━━┈┈━━┈┈━═══════════⌟       " << endl;
     cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
     cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout <<"   "<<endl;
     cout <<"   "<<endl;
    cout <<"   "<<endl;
    cout << "Presione doble ENTER para ingresar al menu principal" << endl;
    cin.ignore();
    cin.get();
    system("cls");
    int opcion;
    do {
    cout <<"   "<<endl;
    cout <<"   "<<endl;
        cout << "                                                               ┈┈━━┈┈━━┈┈━━┈┈" << endl;
        cout << "                                                               ┊  Opciones  ┊" << endl;
        cout << "                                                               ┈┈━━┈┈━━┈┈━━┈┈" << endl;

    	cout << "                                   --------------------------------------------------------------------" << endl;
        cout << "                                   | 1. Registro de productos                                         |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
        cout << "                                   | 2. Actualizacion de inventario                                   |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
        cout << "                                   | 3. Vender producto                                               |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
        cout << "                                   | 4. Consulta de inventario                                        |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
        cout << "                                   | 5. Desarrolladores                                               |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
		cout << "                                   | 6. Salir                                                         |" << endl;
        cout << "                                   --------------------------------------------------------------------" << endl;
		cout <<"   "<<endl;
        cout <<"   "<<endl;
        cout <<"   "<<endl;
        cout << "Seleccione una opción y presione enter: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                actualizarInventario();
                break;
            case 3:
                venderProducto();
                break;
            case 4:
                imprimirInventario(inventario);
                cout << "Presione ENTER para regresar al menú" << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 5:
			    cout<<"Amarilis Ramos."<<endl;
			    cout<<"Daniel Rivera."<<endl;
			    cout<<"Victoria López."<<endl;
			    cout<<"Tatiana López."<<endl;

            case 6
			:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opcion válida." << endl;
        }

    } while (opcion != 5);

    return 0;
}
