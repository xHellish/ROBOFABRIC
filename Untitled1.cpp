#include <iostream>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

int main() {
    // Obtén la ruta del directorio que contiene el ejecutable
    path rutaEjecutable = fs::current_path();
    
    cout << "La ruta del directorio que contiene el ejecutable es: " << rutaEjecutable << std::endl;
    
    return 0;
}