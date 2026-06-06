#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Venta {
    string nombreCliente;
    string numFactura;
    string codigoProducto;
    string nombreProducto;
    double precioUnitario;
    int cantidad;

    double subtotal;
    double descuento;
    double iva;
    double total;
};

void menuPrincipal(vector<Venta>& ventas);
void registrarVenta(vector<Venta>& ventas);
void consultarVentas(const vector<Venta>& ventas);
void buscarPorFactura(const vector<Venta>& ventas);
void reporteGeneral(const vector<Venta>& ventas);
void mostrarDetalleVenta(const Venta& v);


double leerDoublePositivo(string mensaje);
int leerIntPositivo(string mensaje);

string leerSoloLetras(string mensaje);
string leerSoloNumerosOTexto(string mensaje, bool forzarSoloNumeros);

int main() {
    vector<Venta> listaVentas;
    menuPrincipal(listaVentas);
    return 0;
}


void menuPrincipal(vector<Venta>& ventas) {
    int opcion;
    do {
        cout << "\n=============================================" << endl;
        cout << "      SUPER TIENDA EL AHORRO, S.A.           " << endl;
        cout << "=============================================" << endl;
        cout << "1. Registrar Venta" << endl;
        cout << "2. Consultar Ventas Registradas" << endl;
        cout << "3. Buscar Venta por Numero de Factura" << endl;
        cout << "4. Reporte General de Ventas" << endl;
        cout << "5. Salir del Programa" << endl;
        cout << "=============================================" << endl;
        cout << "Seleccione una opcion: ";
        
        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cout << "Opcion invalida. Ingrese un numero entre 1 y 5: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(); 

        switch (opcion) {
            case 1: registrarVenta(ventas); break;
            case 2: consultarVentas(ventas); break;
            case 3: buscarPorFactura(ventas); break;
            case 4: reporteGeneral(ventas); break;
            case 5: cout << "\nGracias por utilizar el sistema. ¡Hasta pronto!\n" << endl; break;
        }
    } while (opcion != 5);
}


void registrarVenta(vector<Venta>& ventas) {
    Venta nuevaVenta;
    cout << "\n--- REGISTRAR NUEVA VENTA ---" << endl;
   
    nuevaVenta.nombreCliente = leerSoloLetras("Nombre del cliente: ");
    
  
    nuevaVenta.numFactura = leerSoloNumerosOTexto("Numero de factura: ", true); 
    

    nuevaVenta.codigoProducto = leerSoloNumerosOTexto("Codigo del producto: ", false); 

    nuevaVenta.nombreProducto = leerSoloLetras("Nombre del producto: "); 
    

    nuevaVenta.precioUnitario = leerDoublePositivo("Precio unitario del producto: ");
    nuevaVenta.cantidad = leerIntPositivo("Cantidad de unidades compradas: ");


    nuevaVenta.subtotal = nuevaVenta.cantidad * nuevaVenta.precioUnitario;
    

    if (nuevaVenta.subtotal > 100.0) {
        nuevaVenta.descuento = nuevaVenta.subtotal * 0.05;
    } else {
        nuevaVenta.descuento = 0.0;
    }
    
    nuevaVenta.iva = (nuevaVenta.subtotal - nuevaVenta.descuento) * 0.12;
    nuevaVenta.total = nuevaVenta.subtotal - nuevaVenta.descuento + nuevaVenta.iva;
    
    ventas.push_back(nuevaVenta);
    
    cout << "\n¡Venta registrada con exito!" << endl;
    mostrarDetalleVenta(nuevaVenta);
}

void consultarVentas(const vector<Venta>& ventas) {
    cout << "\n--- CONSULTAR VENTAS REGISTRADAS ---" << endl;
    if (ventas.empty()) {
        cout << "No hay ventas registradas en el sistema." << endl;
        return;
    }
    
    for (size_t i = 0; i < ventas.size(); i++) {
        cout << "\n--- Venta #" << i + 1 << " ---" << endl;
        mostrarDetalleVenta(ventas[i]);
    }
}


void buscarPorFactura(const vector<Venta>& ventas) {
    cout << "\n--- BUSCAR VENTA POR FACTURA ---" << endl;
    if (ventas.empty()) {
        cout << "No hay ventas registradas en el sistema." << endl;
        return;
    }
    
    string facturaBuscar;
    cout << "Ingrese el numero de factura a buscar: ";
    getline(cin, facturaBuscar);
    
    bool encontrada = false;
    for (const auto& v : ventas) {
        if (v.numFactura == facturaBuscar) {
            cout << "\n--- Factura Encontrada ---" << endl;
            mostrarDetalleVenta(v);
            encontrada = true;
            break; 
        }
    }
    
    if (!encontrada) {
        cout << "No se encontro ninguna factura con el numero: " << facturaBuscar << endl;
    }
}


void reporteGeneral(const vector<Venta>& ventas) {
    cout << "\n--- REPORTE GENERAL DE VENTAS ---" << endl;
    if (ventas.empty()) {
        cout << "No hay datos para generar el reporte." << endl;
        return;
    }
    
    double acumuladoSubtotal = 0;
    double acumuladoDescuento = 0;
    double acumuladoIva = 0;
    double acumuladoTotal = 0;
    
    cout << fixed << setprecision(2);
    cout << left << setw(12) << "Factura" 
         << setw(18) << "Cliente" 
         << setw(12) << "Subtotal" 
         << setw(12) << "Descuento" 
         << setw(10) << "IVA" 
         << setw(12) << "Total" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    
    for (const auto& v : ventas) {
        cout << left << setw(12) << v.numFactura 
             << setw(18) << (v.nombreCliente.length() > 15 ? v.nombreCliente.substr(0, 12) + "..." : v.nombreCliente)
             << "Q." << setw(9) << v.subtotal 
             << "Q." << setw(9) << v.descuento 
             << "Q." << setw(7) << v.iva 
             << "Q." << setw(10) << v.total << endl;
             
        acumuladoSubtotal += v.subtotal;
        acumuladoDescuento += v.descuento;
        acumuladoIva += v.iva;
        acumuladoTotal += v.total;
    }
    
    cout << "----------------------------------------------------------------------------" << endl;
    cout << left << setw(30) << "TOTALES GENERALES:" 
         << "Q." << setw(9) << acumuladoSubtotal 
         << "Q." << setw(9) << acumuladoDescuento 
         << "Q." << setw(7) << acumuladoIva 
         << "Q." << setw(10) << acumuladoTotal << endl;
    cout << "Cantidad total de transacciones: " << ventas.size() << endl;
}


void mostrarDetalleVenta(const Venta& v) {
    cout << fixed << setprecision(2);
    cout << "---------------------------------------" << endl;
    cout << "Factura No:       " << v.numFactura << endl;
    cout << "Cliente:          " << v.nombreCliente << endl;
    cout << "Producto:         [" << v.codigoProducto << "] " << v.nombreProducto << endl;
    cout << "Precio Unitario:  Q." << v.precioUnitario << endl;
    cout << "Cantidad:         " << v.cantidad << endl;
    cout << "-> Subtotal:      Q." << v.subtotal << endl;
    cout << "-> Descuento:     Q." << v.descuento << endl;
    cout << "-> IVA (12%):     Q." << v.iva << endl;
    cout << ">> TOTAL COMPRA:  Q." << v.total << endl;
    cout << "---------------------------------------" << endl;
}

string leerSoloLetras(string mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        
        if (entrada.empty()) {
            cout << "[Error] El campo no puede quedar vacio." << endl;
            continue;
        }
        
        bool esValido = true;
        for (size_t i = 0; i < entrada.length(); i++) {
            char c = entrada[i];
            
            bool esLetraMayuscula = (c >= 'A' && c <= 'Z');
            bool esLetraMinuscula = (c >= 'a' && c <= 'z');
            bool esEspacio = (c == ' ');
            
            if (!esLetraMayuscula && !esLetraMinuscula && !esEspacio) {
                esValido = false;
                break;
            }
        }
        
        if (esValido) return entrada;
        cout << "[Error] Este campo solo acepta letras y espacios." << endl;
    }
}

string leerSoloNumerosOTexto(string mensaje, bool forzarSoloNumeros) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        
        if (entrada.empty()) {
            cout << "[Error] El campo no puede quedar vacio." << endl;
            continue;
        }
        
        if (forzarSoloNumeros) {
            bool esNumero = true;
            for (size_t i = 0; i < entrada.length(); i++) {
                char c = entrada[i];
                if (c < '0' || c > '9') {
                    esNumero = false;
                    break;
                }
            }
            if (!esNumero) {
                cout << "[Error] Este campo requiere unicamente digitos numericos." << endl;
                continue;
            }
        }
        
        return entrada;
    }
}

double leerDoublePositivo(string mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= 0) {
            cin.ignore(10000, '\n');
            return valor;
        }
        cout << "[Error] Ingrese un monto numerico valido y mayor o igual a cero." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int leerIntPositivo(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor > 0) {
            cin.ignore(10000, '\n');
            return valor;
        }
        cout << "[Error] Ingrese una cantidad entera mayor a cero." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}