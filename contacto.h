#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>

class Contacto
{
private:
    
    std::string apellido;
    std::string correo;
    int nacimiento;
    std::string telefono;
public:
    Contacto();
    Contacto(std::string const & _apellido,std::string const & _correo, int _nacimiento, std::string const & _telefono);
   
    std::string getApellido() const;
    std::string getCorreo() const;
    
    void setApellido(const std::string &value);
    void setCorreo(const std::string &value);
    int getNacimiento() const;
    void setNacimiento(int value);
    std::string getTelefono() const;
    void setTelefono(std::string value);
};

std::ostream & operator<<(std::ostream & os, Contacto const & p);
#endif // CONTACTO_H