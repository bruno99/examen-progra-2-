#ifndef DATA_T
#define DATA_T
#include <iostream>

template<typename T>
class Data
{
private:
    std::string nombre;
    T valor;
public:
    Data(std::string const& _nombre, T const & _valor);
    std::string getNombre() const;
    void setNombre(const std::string &value);
    T getValor() const;
    void setValor(const T &value);
};

template<typename T>
Data<T>::Data(const std::string & _nombre, const T &_valor)
{
    nombre = _nombre;
    valor = _valor;
}

template<typename T>
std::string Data<T>::getNombre() const
{
    return nombre;
}

template<typename T>
void Data<T>::setNombre(const std::string &value)
{
    nombre = value;
}

template<typename T>
T Data<T>::getValor() const
{
    return valor;
}

template<typename T>
void Data<T>::setValor(const T &value)
{
    valor = value;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Data<T> const & d){
    os<<d.getNombre()<<":\n"<<d.getValor()<<"\n";
    return os;
}
#endif // DATA_T