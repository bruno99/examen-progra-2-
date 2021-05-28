#ifndef AGENDA_H
#define AGENDA_H
#include "data.h"
#include "contacto.h"
#include <vector>
#include <memory>
#include <functional>

template<typename T>
class Agenda
{
private:
    std::vector<std::shared_ptr<Data<T>>>datos;
public:
    Agenda();
    void inserta(std::shared_ptr<Data<T> > a);
    void elimina(std::string const& nombre);
    std::shared_ptr<Data<T> > find(const std::function<bool(std::shared_ptr<Data<T> >)> &op)const;
    std::vector<std::shared_ptr<Data<T> > > getDatos() const;
};


template<typename T>
Agenda<T>::Agenda()
{

}

template<typename T>
void Agenda<T>::inserta(std::shared_ptr<Data<T> > a)
{
    //el nombre al nos ser unico no hace falta comprobar que no se repite
    datos.push_back(a);
}

template<typename T>
void Agenda<T>::elimina(const std::string &nombre)
{
    for(unsigned int long i{0}; i < datos.size(); i++){
        if(datos.at(i)->getNombre() == nombre){
            datos.erase(datos.begin()+i);
            return;
        }
    }

    throw std::string{"No existe el contacto que quieres borrar"};
}

template<typename T>
std::shared_ptr<Data<T> > Agenda<T>::find(std::function<bool (std::shared_ptr<Data<T> >)> const & op) const
{
    for(auto n:datos){
        if(op(n))return n;
    }
    return nullptr;
}

template<typename T>
std::vector<std::shared_ptr<Data<T> > > Agenda<T>::getDatos() const
{
    return datos;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Agenda<T> const & l){
    for(auto n: l.getDatos()){
        os<<*n<<"\n";
    }
    os<<"\n";
    return os;
}

template<typename T>
Agenda<T> operator+(Agenda<T> const& s, Agenda<T> const & l){
    Agenda<T> result = s;
    for(auto n: l.getDatos()){
        result.inserta(n);
    }
    return result;
}

#endif // AGENDA_H