
typedef struct
{
    int id;
    char nombre[128];
}Piloto;

Piloto* piloto_new();
int cargarpiloto(LinkedList* pArrayList);
int piloto_setId(Piloto* this,int id);
int piloto_getId(Piloto* this,int* id);
int piloto_setNombre(Piloto* this,char* nombre);
int piloto_getNombre(Piloto* this,char* nombre);
