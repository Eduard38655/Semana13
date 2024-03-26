#include <iostream>
#include <string>
#include <vector>

class Persona {
private:
    std::string nombre;
    std::string cedula;
    char sexo;
    Persona* padre;
    Persona* madre;
    std::vector<Persona*> hermanos;
    std::vector<Persona*> hermanas;
    std::vector<Persona*> abuelos;
    std::vector<Persona*> tios;
    std::vector<Persona*> tias;

public:
    Persona(const std::string& nombre, const std::string& cedula, char sexo)
        : nombre(nombre), cedula(cedula), sexo(sexo), padre(nullptr), madre(nullptr) {}

    // Métodos para establecer relaciones
    void asignarPadre(Persona* p) {
        padre = p;
    }

    void asignarMadre(Persona* m) {
        madre = m;
    }

    void agregarHermano(Persona* h) {
        hermanos.push_back(h);
    }

    void agregarHermana(Persona* h) {
        hermanas.push_back(h);
    }

    void agregarAbuelo(Persona* a) {
        abuelos.push_back(a);
    }

    void agregarAbuela(Persona* a) {
        abuelos.push_back(a);
    }

    void agregarTio(Persona* t) {
        tios.push_back(t);
    }

    void agregarTia(Persona* t) {
        tias.push_back(t);
    }

    // Métodos para obtener información
    std::string obtenerNombre() const {
        return nombre;
    }

    std::string obtenerCedula() const {
        return cedula;
    }

    char obtenerSexo() const {
        return sexo;
    }

    Persona* obtenerPadre() const {
        return padre;
    }

    Persona* obtenerMadre() const {
        return madre;
    }

    std::vector<Persona*> obtenerHermanos() const {
        return hermanos;
    }

    std::vector<Persona*> obtenerHermanas() const {
        return hermanas;
    }

    std::vector<Persona*> obtenerAbuelos() const {
        return abuelos;
    }

    std::vector<Persona*> obtenerTios() const {
        return tios;
    }

    std::vector<Persona*> obtenerTias() const {
        return tias;
    }
};

int main() {
    // Crear personas
    Persona abuelo_paterno("Juan", "111111111", 'M');
    Persona abuela_paterna("Maria", "222222222", 'F');
    Persona abuelo_materno("Pedro", "333333333", 'M');
    Persona abuela_materna("Ana", "444444444", 'F');
    Persona padre("Jose", "555555555", 'M');
    Persona madre("Laura", "666666666", 'F');
    Persona hijo("Pedrito", "777777777", 'M');
    Persona tio("Carlos", "888888888", 'M');
    Persona tia("Sofia", "999999999", 'F');
    Persona hermano("Juanito", "101010101", 'M');
    Persona hermana("Lucia", "121212121", 'F');

    // Establecer relaciones
    hijo.asignarPadre(&padre);
    hijo.asignarMadre(&madre);

    hijo.agregarAbuelo(&abuelo_paterno);
    hijo.agregarAbuelo(&abuelo_materno);
    hijo.agregarAbuela(&abuela_paterna);
    hijo.agregarAbuela(&abuela_materna);

    padre.agregarHermano(&tio);
    madre.agregarHermana(&tia);

    // Imprimir información
    std::cout << "Nombre: " << hijo.obtenerNombre() << std::endl;
    std::cout << "Cédula: " << hijo.obtenerCedula() << std::endl;
    std::cout << "Sexo: " << hijo.obtenerSexo() << std::endl;
    std::cout << "Padre: " << hijo.obtenerPadre()->obtenerNombre() << std::endl;
    std::cout << "Madre: " << hijo.obtenerMadre()->obtenerNombre() << std::endl;

    std::cout << "Abuelos:" << std::endl;
    for (auto abuelo : hijo.obtenerAbuelos()) {
        std::cout << "- " << abuelo->obtenerNombre() << std::endl;
    }

    std::cout << "Tíos:" << std::endl;
    for (auto tio : hijo.obtenerTios()) {
        std::cout << "- " << tio->obtenerNombre() << std::endl;
    }

    std::cout << "Tías:" << std::endl;
    for (auto tia : hijo.obtenerTias()) {
        std::cout << "- " << tia->obtenerNombre() << std::endl;
    }

    std::cout << "Hermanos:" << std::endl;
    for (auto hermano : padre.obtenerHermanos()) {
        std::cout << "- " << hermano->obtenerNombre() << std::endl;
    }

    std::cout << "Hermanas:" << std::endl;
    for (auto hermana : madre.obtenerHermanas()) {
        std::cout << "- " << hermana->obtenerNombre() << std::endl;
    }

    return 0;
}
