
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[128];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

Vuelo* vuelo_new();
Vuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);
void vuelo_delete(Vuelo* this);

int vuelo_setIdVuelo(Vuelo* this,int idVuelo);
int vuelo_getIdVuelo(Vuelo* this,int* idVuelo);
int vuelo_setIdAvion(Vuelo* this,int idAvion);
int vuelo_getIdAvion(Vuelo* this,int* idAvion);
int vuelo_setIdPiloto(Vuelo* this,int idPiloto);
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto);
int vuelo_setFecha(Vuelo* this,char* fecha);
int vuelo_getFecha(Vuelo* this,char* fecha);
int vuelo_setDestino(Vuelo* this,char* destino);
int vuelo_getDestino(Vuelo* this,char* destino);
int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros);
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros);
int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue);
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue);
int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada);
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada);
