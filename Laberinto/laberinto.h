#include <iostream>
#include <vector>

using namespace std;


void unirNodos2(vector<vector<char>>& vert, char u, char v) {
    vert[u].push_back(v);
   
}

vector<vector<char>> mostrar(vector<vector<char>> matriz, int n, int m) {
    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";

    }


    cout << "\n\n";

    return matriz;
}


vector<vector<char>> posicion(vector<vector<char>> matriz, int px, int py, int x, int y) {
    int loc;
    string message;
    cout << "A dondete quieres mover";
    cout << "1.arriba,2.abajo,3.izquierda,4.derecha";
    cin >> loc;
    switch (loc) {

    case 1: {
        if (py > 0 && matriz[px][py - 1] != 'X')
        {

            if (matriz[px][py - 1] == 'T')
            {
                message = "Has ganado un tesoro";
                break;
            }
            else if (matriz[px][py - 1] == '.') {
                matriz[px][py - 1];
                message = "Avanzaste hacia arriba";
                break;
            }

        }
        message = "No puedes pasar por aqui";
        break;
    }
    case 2: {
        if (py <= y && matriz[px][py + 1] != 'X')
        {
            if (matriz[px][py + 1] == 'T')
            {
                message = "Has ganado un tesoro";
                break;
            }
            else if (matriz[px][py + 1] == '.') {
                matriz[px][py + 1];
                message = "Avanzaste hacia arriba";
                break;
            }
        }
        message = "No puedes pasar por aqui";
        break;
    }
    case 3: {
        if (px > 0 && matriz[px - 1][py] != 'X')
        {
            if (matriz[px - 1][py] == 'T')
            {
                message = "Has ganado un tesoro";
                break;
            }
            else if (matriz[px - 1][py] == '.') {
                matriz[px - 1][py];
                message = "Avanzaste hacia arriba";
                break;
            }
        }
        message = "No puedes pasar por aqui";
        break;

    }
    case 4: {
        if (px < x && matriz[px + 1][py] != 'X')
        {
            if (matriz[px + 1][py] == 'T')
            {
                message = "Has ganado un tesoro";
                break;
            }
            else if (matriz[px + 1][py] == '.') {
                matriz[px + 1][py];
                message = "Avanzaste hacia arriba";
                break;
            }
        }
        message = "No puedes pasar por aqui";
        break;
    }
    };
    cout << message;
    mostrar(matriz, x, y);

    return matriz;
}



//Inicilizador 
vector<vector<char>> Eje_2() {
    int n, m;
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;
    cout << "\n";
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> m;
    cout << "\n";

    vector<vector<char>> matriz(n, vector<char>(m));
    vector<vector<char>> G(n);


    cout << "Ingrese los elementos de la matriz por fila:" << endl;
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "Fila " << i + 1 << ":" << endl;
        cout << "\n";
        for (int j = 0; j < m; ++j) {
            cout << "Columna " << j + 1 << ": ";
            char valor ; 
            cin >> valor; 
            // Validar que el valor sea 0 o 1
            while (valor != 'X'  && valor != '.' && valor != 'T' ) {
                cout << "\n";
                cout << "Error: solo se pueden agregar X para pared, puntos(.) para caminos y T para el tesoro. Intente de nuevo." << endl;
                cout << "\n";
                cout << "Columna " << j + 1 << ": ";
                cin >> valor;
            }
            matriz[i][j] = valor;
            if (valor == 1) {
                unirNodos2(G, i, j);
            }
            cout << "\n";
        }
    }

    // Mostrar la matriz
    mostrar(matriz, n, m); 

    cout << "\n\n";
 
    cout << "Ubicaciones disponible para poner personaje:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matriz[i][j] =='.')
            {
                cout << matriz[i][j] << " ";
                cout << "Fila y columna: " + i , j;  
                
            }

        }
        cout << "\n";

    }
    int pn, pm; 

    cout << "Ingresa la ubicacion que quieres FILA";
    cin >> pn;
    cout << "Ingresa la ubicacion que quieres COLUMNA";
    cin >> pm; 
    matriz[pn][pm] = 'P';
    cout << "\n";
    // Mostrar la matriz
    mostrar(matriz, n, m); 

    
    
    int opcion; 
    do {
        cout << "\t---------QUE EMPIEZE EL JUEGO---------\n";
        cout << "\n1. Ejercicio 1\n";
        cout << "\n9. Salir del Menu\n";
       
        cin >> opcion; 


        switch (opcion) { 

        case 1: {
            posicion(matriz, pn, pm, n, m);  
        }

        };
        system("cls");
    } while (opcion != 9);
    

    cout << "\n\n";

    return matriz;
}

   





