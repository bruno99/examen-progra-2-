#include "agenda.h"
using namespace std;

int main()
{
    Agenda<Contacto> agendaContactos;
    bool condicion = true;
    int accion, nacimiento;
    string nombre;
    string apellido;
    string correo;
    string telefono;

    while(condicion == true){
        cout<<"1.\tAñadir Contacto\n"
        <<"2.\tBorrar Contacto\n"
        <<"3.\tBuscar Contacto por nombre\n"
        <<"4.\tBuscar Contacto por cumpleaños\n"
        <<"5.\tMostrar Contacto \n"
        <<"6.\tContactos que cumplen entre 2 fechas\n"
        <<"7.\tListar\n"
        <<"8.\tAcabar Programa\n"
        <<"Elige una accion:";
        cin>>accion;
        while(accion < 1 || accion > 5){
            cout<<"Accion no valida por favor elija una correcta: ";
            cin>>accion;
        }

        cout<<endl;
        switch (accion) {
            case 1:
                cout<<"Introduce el nombre del contacto:";cin>>nombre;
                cout<<"Introduce el apellido del contacto:";cin>>apellido;
                cout<<"Introduce el año de nacimiento del contacto:(formato XXXXXX)";cin>>nacimiento;
                cout<<"Introduce el correo del contacto:";cin>>correo;
                cout<<"Introduce el telefono del contacto:";cin>>telefono;
                cout<<endl;
                try {
                    auto a = std::make_shared<Data<Contacto>>(Data<Contacto>(nombre,Contacto{apellido, correo, nacimiento,telefono}));
                    agendaContactos.inserta(a);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 2:
                try {
                    cout<<"Introduce el nombre del contacto a borrar:";cin>>nombre;
                    cout<<endl;
                    agendaContactos.elimina(nombre);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 3:
                try {
                    cout<<"Introduce el nombre del contacto que deseas buscar:";cin>>nombre;
                    auto encontrada = agendaContactos.find([=](std::shared_ptr<Data<Contacto> > a){
                        return a->getNombre() == nombre;
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else std::cout << "Contacto no encontrado\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 4:
                try {
                    cout<<"Introduce el nombre del contacto que deseas mostrar:";cin>>nombre;
                    /*auto encontrada = agendaContactos.find( [=](std::shared_ptr<Data<Contacto> > a){
                        return a->getNombre() = nombre;
                        //return a->getNombre().data; datos de el contacto con ese nombre
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else */std::cout << "Contacto no encontrado\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 5:
                try {
                    int fecha1, fecha2;
                    cout<<"Introduce la primera fecha:";cin>>fecha1;
                    cout<<"Introduce la segunda fecha:";cin>>fecha2;
                    auto encontrada = agendaContactos.find([=](std::shared_ptr<Data<Contacto> > a){
                        //if(a->getNombre.nacimiento > fecha1 && a->getNombre.nacimiento < fecha 2)
                        return a->getNombre() == nombre;
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else std::cout << "Contacto no encontrado\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 6:
                try {
                    cout<<"Introduce el nacimiento del contacto que deseas buscar:";cin>>nacimiento;
                    auto encontrada = agendaContactos.find([=](std::shared_ptr<Data<Contacto> > a){
                        return a->getNombre() == nombre;
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else std::cout << "Contacto no encontrado\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;    
            case 7:
                cout<<agendaContactos;
                break;
            case 8:
                condicion = false;
                break;
        }
    }
    return 0;
}