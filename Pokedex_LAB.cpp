#include <iostream>
#include <sstream>
#include <fstream>
//#define NOMBRE_ARCHIVO "C:\Users\ashle\OneDrive\Desktop\ArchivosProyecto1\archivo2.csv"
using namespace std;



class Pokemon {
private:  //Atributos
    string generacion;
    string nombre;
    string national;
public:
    Pokemon(string, string, string);
    void leer();
    string getGen();
    string getNombre();
    string getNational();

};
//Constructor
Pokemon::Pokemon(string _gen, string _nombre, string _national) {
    generacion = _gen;
    nombre = _nombre;
    national = _national;
}

void Pokemon::leer() {
    cout << "=============================" << endl;
    cout << "Generacion: " << generacion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "National: " << national << endl;


}

string Pokemon::getGen() {
    return generacion;
}

string Pokemon::getNombre() {
    return nombre;
}

string Pokemon::getNational() {
    return national;
}



//---------------SIMPLE2---------------------------------------


struct Node {
    int generacion;
    string nombre;
    int national;
    struct Node* next;
};


void push(struct Node** head_ref, int _gen, string _nombre, int _national)
{

    struct Node* new_node = new Node;


    new_node->generacion = _gen;
    new_node->nombre = _nombre;
    new_node->national = _national;



    new_node->next = (*head_ref);


    (*head_ref) = new_node;
}

void selectionSort(struct Node* head)
{
    Node* temp = head;


    while (temp) {
        Node* min = temp;
        Node* r = temp->next;


        while (r) {
            if (min->generacion > r->generacion)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = temp->generacion;
        temp->generacion = min->generacion;
        min->generacion = x;
        temp = temp->next;
    }
}

void selectionSort2(struct Node* head)
{
    Node* temp = head;


    while (temp) {
        Node* min = temp;
        Node* r = temp->next;


        while (r) {
            if (min->national > r->national)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = temp->national;
        temp->national = min->national;
        min->national = x;
        temp = temp->next;
    }
}

void printList4(struct Node* node)
{
    while (node != NULL) {
        cout << node->generacion << ", " << node->nombre << ", " << node->national << endl;
        node = node->next;
    }
    printf("\n");
}

void printList5(struct Node* node)
{
    while (node != NULL) {
        cout << node->national << ", " << node->nombre << ", " << node->generacion << endl;
        node = node->next;
    }
    printf("\n");
}


void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->generacion << ", " << node->nombre << ", " << node->national << endl;
        node = node->next;
    }
    printf("\n");
}



void printList2(struct Node* node)
{
    while (node != NULL) {
        cout << node->national << ", " << node->nombre << ", " << node->generacion << endl;
        node = node->next;
    }
    printf("\n");
}


struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

struct Node* partition(struct Node* head, struct Node* end,
    struct Node** newHead,
    struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node* prev = NULL, * cur = head, * tail = pivot;


    while (cur != pivot) {
        if (cur->generacion < pivot->generacion) {

            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {

            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;


    (*newEnd) = tail;


    return pivot;
}


struct Node* quickSortRecur(struct Node* head,
    struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;

    Node* newHead = NULL, * newEnd = NULL;

    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct Node* pivot
        = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
    (*headRef)
        = quickSortRecur(*headRef, getTail(*headRef));
    return;
}




struct Node* partition2(struct Node* head, struct Node* end,
    struct Node** newHead,
    struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node* prev = NULL, * cur = head, * tail = pivot;


    while (cur != pivot) {
        if (cur->national < pivot->national) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }


    if ((*newHead) == NULL)
        (*newHead) = pivot;


    (*newEnd) = tail;


    return pivot;
}


struct Node* quickSortRecur2(struct Node* head,
    struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;

    Node* newHead = NULL, * newEnd = NULL;


    struct Node* pivot
        = partition2(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur2(newHead, tmp);

        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur2(pivot->next, newEnd);

    return newHead;
}


void quickSort2(struct Node** headRef)
{
    (*headRef)
        = quickSortRecur2(*headRef, getTail(*headRef));
    return;
}

//------------------------------------------------------------

//-------------------LISTA SIMPLE-------------------------------------------


struct nodo {
    //int nro;        // en este caso es un numero entero
    int generacion;
    string nombre;
    int national;
    struct nodo* sgte;
};

typedef struct nodo* Tlista;

void insertarInicio(Tlista& lista, int _gen, string _nombre, int _national)
{
    Tlista q;
    q = new(struct nodo);
    q->generacion = _gen;
    q->nombre = _nombre;
    q->national = _national;
    q->sgte = lista;
    lista = q;
}






void buscarElemento(Tlista lista, int _gen, string _nombre, int _national)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while (q != NULL)
    {
        if (q->generacion == _gen)
        {
            if (q->nombre == _nombre)
            {
                if (q->national == _national)
                {
                    cout << endl << " Encontrada en posicion " << i << endl;
                    band = 1;
                }

            }


        }
        q = q->sgte;
        i++;
    }

    if (band == 0)
        cout << "\n\n Numero no encontrado..!" << endl;
}

void reportarLista(Tlista lista)
{
    int i = 0;

    while (lista != NULL)
    {
        cout << ' ' << i + 1 << ") " << lista->generacion << ", " << lista->nombre << ", " << lista->national << endl;
        lista = lista->sgte;
        i++;
    }
}

// Shell sort
void shellSort(int array[], int n) {

    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void menu1()
{
    cout << "\n\t\tOrdenamientos\n\n";
    cout << " 1. INGRESAR ARCHIVO                               " << endl;
    cout << " 2. ORDENAR POR GENERACION - SELECTION SORT        " << endl;
    cout << " 3. ORDENAR POR GENERACION - QUICK SORT            " << endl;
    cout << " 4. ORDENAR POR GENERACION - SHELL SORT            " << endl;
    cout << " 5. ORDENAR POR NATIONAL NUMBER - SELECTION SORT   " << endl;
    cout << " 6. ORDENAR POR NATIONAL NUMBER - QUICK SORT       " << endl;
    cout << " 7. ORDENAR POR NATIONAL NUMBER - SHELL SORT       " << endl;
    cout << " 8. SALIR                                          " << endl;

    cout << "\n INGRESE OPCION: ";
}


//C:\\Users\\ashle\\OneDrive\\Desktop\\pokedex\\Pokedex\\pokemon.csv

//-----------------------------------------------------------------------------


int main()
{

    Tlista lista = NULL;
    struct Node* a = NULL;
    //C:\\Users\\marco\\OneDrive\\Escritorio\\Pokedex\\pokemon.csv

    string str = "";
    cout << "INGRESE LA RUTA DEL ARCHIVO \n";
    cin >> str;

    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar

    ifstream archivo(str);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas


    system("color 0b");

    do
    {
        menu1();  cin >> op;

        switch (op)
        {
        case 1:

            while (getline(archivo, linea))
            {

                stringstream stream(linea); // Convertir la cadena a un stream
                string generacion;
                string nombre;
                string national;



                // Extraer todos los valores de esa fila
                getline(stream, generacion, delimitador);
                getline(stream, nombre, delimitador);
                getline(stream, national, delimitador);

                int num;
                num = std::stoi(generacion);
                int num2;
                num2 = std::stoi(national);

                // Pokemon p1 = Pokemon(generacion, nombre, national);
                push(&a, num, nombre, num2);









            }

            break;


        case 2:

            cout << "Lista antes de ordenamiento SELECTION SORT \n";
            printList4(a);

            selectionSort(a);

            cout << "Lista despues de ordenamiento SLECTION SORT \n";
            printList4(a);



            break;


        case 3:
            cout << "Lista antes de ordenamiento QUICK SORT\n";
            printList(a);

            quickSort(&a);

            cout << "Lista despues de ordenamiento  QUICK SORT \n";
            printList(a);


            break;


        case 4:

            cout << "Lista antes de ordenamiento Shell Sort  \n";
            printList4(a);

            selectionSort(a);

            cout << "Lista despues de ordenamiento Shell Sort  \n";
            printList4(a);


            break;


        case 5:
            cout << "Lista antes de ordenamiento SELECTION SORT \n";
            printList5(a);

            selectionSort2(a);

            cout << "Lista despues de ordenamiento SELECTION SORT \n";
            printList5(a);



            break;

        case 6:
            cout << "Lista antes de ordenamiento QUICK SORT \n";
            printList2(a);

            quickSort2(&a);

            cout << "Lista despues de ordenamiento QUICK SORT \n";
            printList2(a);



            break;

        case 7:


            quickSort2(&a);

            cout << "Lista despues de ordenamiento Shell Sort \n";
            printList2(a);



            break;

        }

        cout << endl << endl;
        system("pause");  system("cls");

    } while (op != 8);


    system("pause");







    archivo.close();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
