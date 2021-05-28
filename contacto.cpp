#include "contacto.h"


std::string Contacto::getApellido() const
{
    return apellido;
}

void Contacto::setApellido(const std::string &value)
{
    if(value.size()==0)throw std::string{"Apellido no puede ir en blanco"};
    apellido = value;
}

std::string Contacto::getCorreo() const
{
    return correo;
}

void Contacto::setCorreo(const std::string &value)
{
    if(value.size()==0)throw std::string{"Correo no puede ir en blanco"};
    correo = value;
}


int Contacto::getNacimiento() const
{
    return nacimiento;
}

void Contacto::setNacimiento(int value)
{
    nacimiento = value;
}

std::string Contacto::getTelefono() const
{
    return telefono;
}

void Contacto::setTelefono(std::string value)
{
    if(value.size()!=9)throw std::string{"Los telefonos tienen 9 digitos"};
    telefono = value;
}

Contacto::Contacto()
{

}

Contacto::Contacto( const std::string &_apellido, const std::string &_correo, int _nacimiento, const std::string &_telefono)
{
    
    setApellido(_apellido);
    setCorreo(_correo);
    setTelefono(_telefono);
    setNacimiento(_nacimiento);
}

std::ostream &operator<<(std::ostream &os, const Contacto &p)
{
    os<<"}\nApellido{"<<p.getApellido()<<"}\nCorreo{"<<p.getCorreo()<<"}\nNacimiento{"<<p.getNacimiento()<<"}\nTelefono{"<<p.getTelefono()<<"}\n";
    return os;
}