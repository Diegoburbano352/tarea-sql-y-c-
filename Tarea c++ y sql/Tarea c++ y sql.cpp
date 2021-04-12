// Tarea c++ y sql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
int q_estado;

void insert_productos();
void select_productos();
void actualizar_marca();


int main() {
    insert_productos();
    select_productos();
    actualizar_marca();
}


    void insert_productos()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "empresa_tarea", "Empres@345", "db_empresa_tarea", 3306, NULL, 0);
        if (conectar) {
            string producto, descripcion, fecha_ingreso = "now()";
            string id_marca, existencia, precio_costo, precio_venta;

            cout << " Ingrese el producto: \n";
            getline(cin, producto);
            cout << " Ingrese el id_marca: \n";
            cin >> id_marca;
            cin.ignore();
            cout << " Ingrese la descripcion: \n";
            getline(cin, descripcion);
            cout << " Ingrese el precio costo: \n";
            cin >> precio_costo;
            cout << " Ingrese el precio venta: \n";
            cin >> precio_venta;
            cin.ignore();
            cout << " Ingrese la existencia: \n";
            cin >> existencia;
            cout << " \nLa fecha de ingreso sera la hora en la que ingrese los datos " << endl;

            string insert = " insert into productos (producto,descripcion,precio_costo,precio_venta,fecha_ingreso,id_marca,existencia) values ('" + producto + " , '" + descripcion + "' , " + precio_costo + "," + precio_venta + "," + fecha_ingreso + "," + id_marca + "," + existencia + "')";
            const char* i = insert.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << " Insert exitoso... " << endl;
            }
            else
            {
                cout << " Error en el insert... " << endl;
            }

        }
    }
    void select_productos()
    {
        system("cls");
        MYSQL* conectar;
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "empresa_tarea", "Empres@345", "db_empresa_tarea", 3306, NULL, 0);
        if (conectar) {
            string consulta = "Select * from productos";
            const char* c = consulta.c_str();
            q_estado = mysql_query(conectar, c);
            if (!q_estado) {
                resultado = mysql_store_result(conectar);
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << endl;
                }
            }
            else{
                cout << "Error en el select..." << endl;
            }
        }
    }

    void actualizar_marca() {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "empresa_tarea", "Empres@345", "db_empresa_tarea", 3306, NULL, 0);
        if (conectar) {
            int idaux, op = 0;

            while (op != 3) {
               menu_actualizar_marca();
                cout << "Opcion: ";
                cin >> op;

                if (op == 1) {
                    string nid;
                    cout << "Ingrese el id de la marca que quiere modificar: ";
                    cin >> idaux;

                    cout << "Ingrese el nuevo id: ";
                    getline(cin, nid);
                    cin.ignore();

                    string update = "update marcas set (idmarca) values('" + nid + "') where idmarca = idaux ";
                    const char* i = update.c_str();

                    q_estado = mysql_query(conectar, i);
                    if (!q_estado)
                    {
                        cout << "Update exitoso . . ." << endl;
                    }
                    else
                    {
                        cout << "Error en Update . . ." << endl;
                    }
                }

                if (op == 2) {
                    string nmarca;
                    cout << "Ingrese el id de la marca que quiere modificar: ";
                    cin >> idaux;

                    cout << "Ingrese la nueva marca: ";
                    cin >> nmarca;

                    string update = "update marcas set marca='" + nmarca + "' where idmarca = idaux ";
                    const char* i = update.c_str();

                    q_estado = mysql_query(conectar, i);
                    if (!q_estado)
                    {
                        cout << "Update exitoso . . ." << endl;
                    }
                    else
                    {
                        cout << "Error en Update . . ." << endl;
                    }
                }

            }
        }
    }

