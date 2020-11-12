//para poder inicializar la musica debe de implementar la libreria winmm en "link libraries de settngs compiler" 
//tambien encionar que tanto la musica en formato "WAV" como el proyecto "main.cpp"deben estar juntos
               /*|------------------------------------|*/
               /*|              CREADOR@S             |*/
               /*|                                    |*/
               /*|  CARLA PATRICIA COPACALLE TORRICO  |*/
               /*|  ROMAN AREVALO LIBIA NATALY        |*/
               /*|  ALEJANDRA VARGAS ACEVEDO          |*/
               /*|------------------------------------|*/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

/*******************MOVIMIENTO DE LAS TECLAS*********************/

#define ARRIBA        72
#define IZQUIERDA     75
#define DERECHA       77
#define ABAJO         80
#define ESC           27

/*******************INICIAMOS CON VARIABLES GLOBALES*********************/

int xc = 30, yc = 15;//comida "coordenada"
int cuerpo [50][2];
int n = 1;
int tam = 4;
int x = 10;//vibora
int y = 12;
int dir = 3;
int velocidad = 150;
int score = 0;
int h = 1;
char tecla;
int nivel = 1;

void gotoxy(int x, int y){
        HANDLE hCon;
        hCon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X=x;
        dwPos.Y=y;
        SetConsoleCursorPosition(hCon,dwPos);
}

/*******************PINTAMOS EL TABLERO*********************/

void pinta_tablero(){                     //lineas horizontales
    for (int i = 2 ; i<78 ; i++){
        gotoxy(i,3);
        char hor = 219; cout<< hor ;
        gotoxy(i,23);
        char hor2 = 219; cout<< hor2 ;
    }
    for (int i = 4 ; i<23 ; i++){        //lineas verticales
        gotoxy(2,i);
        char ver = 219; cout<< ver ;
        gotoxy(77,i);
        char ver2 = 219; cout<< ver2 ;
    }
}

/*******************DIBUJAMOS LA PORTADA PRICIPAL EL JUEGO*********************/

void portada()
{
        system("cls");
        int c=24,f=79;
        char t=178;    //codigo assci
        for(int i=0 ; i<f ; i++){    // lineas horizontales de la portada
                gotoxy(i,0);
                cout<<t;
                gotoxy(i,c);
                cout<<t;
        }
        for(int i=0 ; i<=c ; i++){    // lineas verticales de la portada
                gotoxy(0,i);
                cout<<t;
                gotoxy(f,i);
                cout<<t;
        }
        // graficamos de modo manual la portada
        gotoxy(20,1); cout << "       ---_ .......---." << endl;
        gotoxy(20,2); cout << "      (|\\\\ /      / /| \\\\ \\\\" << endl;
        gotoxy(20,3); cout << "      /  /     .'  -=-'   `." << endl;
        gotoxy(20,4); cout << "     /  /    .'             )"<< endl;
        gotoxy(20,5); cout << "   _/  /   .'        _.)   /" << endl;
        gotoxy(20,6); cout << "  / o   o        _.-' /  .'" << endl;
        gotoxy(20,7); cout << "  \\\\          .-'    / .'*|" << endl;
        gotoxy(20,8); cout << "   \\\\___.-'//    .'.' \\\\*|" << endl;
        gotoxy(20,9); cout << "    \\\\| \\\\ | //   .'.' _|*|" << endl;
        gotoxy(20,10);cout << "     `   \\\\|//  .'.'_ _ ||" << endl;
        gotoxy(20,11);cout << "      .  .// .'.' | _ _ \\\\|" << endl;
        gotoxy(20,12);cout << "     \\\\`-|\\\\//    \\\\ _ _ \\\\*\\" << endl;
        gotoxy(20,13);cout << "                   \\\\ _ _ \\\\*" << endl;
        gotoxy(20,14);cout << "                    \\\\ _ _ \\\\ " << endl;
        gotoxy(20,15);cout << "                     \\\\_" << endl;

        gotoxy(5,16); cout << "  )\\ )   (              )\\ )  (  ( /(  \\ ))\ ) *   )   (      "   << endl;
        gotoxy(5,17); cout << " (()/(   )\\      (   ( (()/(( )\ )\\())(()/(()/` )  /(   )\\     "  << endl;
        gotoxy(5,18); cout << "  /(_)((((_)(    )\\  )\\ /(_))((_((_)\\  /(_)/(_)( )(_)((((_)(   "  << endl;
        gotoxy(5,19); cout << " (_))  )\\ _ )\\  ((_)((_(_))((_)_  ((_)(_))(_))(_(_()) )\\ _ )\\ "  << endl;
        gotoxy(5,20); cout << " | |   (_)_\\(_) \\ \\ / /|_ _|| _ )/ _ \\| _ |_ _|_   _| (_)_\\(_)" << endl;
        gotoxy(5,21); cout << " | |__  / _ \\    \\ V /  | | | _ | (_) |   /| |  | |    / _ \\  "   << endl;
        gotoxy(5,22); cout << " |____|/_/ \\_\\    \\_/  |___||___/\\___/|_|_|___| |_|   /_/ \\_\\ "<< endl;

        gotoxy(23,23);
        cout<<"Presione ENTER para empezar";
        system("pause>INICIO");
}

/*******************FUNCIONES DEL JUEGO*********************/

void guardar_posicion()
{
    cuerpo[n][0] = x;
    cuerpo[n][1] = y;
    n++;
    if(n == tam)n=1;
}

void pintar_cuerpo()
{
    char t=157;
    for(int i = 1; i < tam; i++){
        gotoxy(cuerpo[i][0],cuerpo[i][1]);
        cout<< t ;
    }
}

void borrar_cuerpo()
{
    gotoxy (cuerpo [n][0], cuerpo[n][1]);
        cout<< "  " ;
}

void cambiar_velocidad(){
    if(score == h*20){
        velocidad -= 10;
        h++;
        nivel++;
    }
}

void comida ()
{    //la comida la programamos de modo random
    if(x == xc && y == yc){
        xc = (rand()%73)+4;
        yc = (rand()%19)+4;

        tam ++;
        score += 10;

        gotoxy(xc,yc);
        char comidita = 169; cout<< comidita ;// con codigo assci dibujamos la comida
        cambiar_velocidad();
    }
}

void puntos()
{
    gotoxy(3,1);
    cout<<"Puntuacion: ";
    cout<<score;
    gotoxy(20,1);
    cout<<"Level: "<<nivel;

  }

/*******************DIBUJAMOS LA PORTADA DEL GAME OVER*********************/

void muerte2()
{
        system("cls");
        int c=24,f=95;
        char t=178;//codigo assci
        for(int i=0 ; i<f ; i++){  // nos muestra las lineas horizontales de la portada
                gotoxy(i,0);
                cout<<t;
                gotoxy(i,c);
                cout<<t;
        }
        for(int i=0 ; i<=c ; i++){ //  nos muestra las lineas verticales de la portada
                gotoxy(0,i);
                cout<<t;
                gotoxy(f,i);
                cout<<t;
        }
         // graficamos de modo manual la portada
        gotoxy(25,1); cout << "       ---_ .......---." << endl;
        gotoxy(25,2);cout << "      (|\\\\ /      / /| \\\\ \\\\" << endl;
        gotoxy(25,3);cout << "      /  /     .'  -=-'   `." << endl;
        gotoxy(25,4);cout << "     /  /    .'             )"<< endl;
        gotoxy(25,5);cout << "   _/  /   .'        _.)   /" << endl;
        gotoxy(25,6);cout << "  / o   o        _.-' /  .'" << endl;
        gotoxy(25,7);cout << "  \\\\          .-'    / .'*|" << endl;
        gotoxy(25,8);cout << "   \\\\___.-'//    .'.' \\\\*|" << endl;
        gotoxy(25,9);cout << "    \\\\| \\\\ | //   .'.' _|*|" << endl;
        gotoxy(25,10);cout << "     `   \\\\|//  .'.'_ _ ||" << endl;
        gotoxy(25,11);cout << "      .  .// .'.' | _ _ \\\\|" << endl;
        gotoxy(25,12);cout << "     \\\\`-|\\\\//    \\\\ _ _ \\\\*\\" << endl;
        gotoxy(25,13);cout << "                   \\\\ _ _ \\\\*" << endl;
        gotoxy(25,14);cout << "                    \\\\ _ _ \\\\ " << endl;
        gotoxy(25,15);cout << "                     \\\\_" << endl;

        gotoxy(3,16); cout << "/ |    /      \\ /      \\/  \\     /  /        |    /      \\/  |     /  /         /     \\ " << endl;
        gotoxy(3,17); cout << "$$|   /$$$$$$  /$$$$$$  $$  \\   /$$ $$$$$$$$/    /$$$$$$  $$ |     $$ $$$$$$$$ /$$$$$$$|" << endl;
        gotoxy(3,18); cout << "$$|   $$ | _$$/$$   |$$ $$$  \\ /$$$ $$ |         $$ |  $$ $$ |   $$ $$ |_      $$ |_ $$ |" << endl;
        gotoxy(3,19); cout << "$$|   $$ |/    $$    $$ $$$$  /$$$$ $$    |      $$ |  $$ $$  \\ /$$/$$    |    $$   $$<" << endl;
        gotoxy(3,20); cout << "$$/   $$ |$$$$ $$$$$$$$ $$ $$ $$/$$ $$$$$/       $$ |  $$ |$$  /$$/ $$$$$/     $$$$$$$|" << endl;
        gotoxy(3,21); cout << "  _   $$ \\_$$  $$ |  $$ $$ |$$$/ $$ $$ |_        $$ \\  $$ | $$ $$/  $$ |__  |  $$|    $$ |" << endl;
        gotoxy(3,22); cout << "/  |  $$   $$/ $$ |  $$ $$ | $/  $$ $$       |   $$    $$/   $$$/   $$        |$$|    $$ |" << endl;
        gotoxy(3,23); cout << "$$/   $$$$$$/  $$/   $$/$$/      $$/$$$$$$$$/      $$$$$$/     $/    $$$$$$$$/ $$/    $$ |"<< endl;
        gotoxy(3,26); cout<< "LOOOOOOSSSSSSEEEEEEEERRRRRRRR!!!!!!!";

        gotoxy(23,26); cout<<"Presione ENTER";

}

/*******************DECLARAMOS LOS LIMITES DEL JUEGO*********************/

bool game_over()
{
    if(y == 3 || y == 23 || x == 2 || x == 77)
        return false;
        for (int j = tam-1 ; j > 0; j--){
            if(cuerpo[j][0] == x && cuerpo[j][1] == y)
            return false;
        }
        return true;
        system("cls");
}

/*******************DECLARAMOS LOS CONTROLES*********************/

void controles()
{
    if(kbhit()){
        tecla = getch();//guarda la tecla
        switch(tecla){
        case ARRIBA:
            if(dir != 2)//distinto de abajo
            dir = 1;
            break;
        case ABAJO:
            if(dir != 1)//distinto de arriba
            dir = 2;
            break;
        case DERECHA:
            if(dir != 4)//distinto de izquierda
            dir =3;
            break;
        case IZQUIERDA:
            if(dir != 3)//distinto de derecha
                dir =4;
                break;
        }
    }
}

/*******************INICIAMOS EL JUEGO*********************/

int main()
{
    PlaySound(TEXT("musica_1594053680798.wav"),NULL,SND_LOOP | SND_ASYNC);
    system("color E0");
    portada();
        system("cls");
        gotoxy(xc,yc);
        char puntito = 169; cout<< puntito ;//la primera fruta
        pinta_tablero();
        while(tecla != ESC  &&  game_over() != false){
        comida();
        puntos();
        borrar_cuerpo();//borra la cajita que declaramos
        guardar_posicion();//creamos una cajita para dibujar en codigo assci
        pintar_cuerpo();//dibujamos en codigo assci
        controles();

        if(dir == 1) y--;
        if(dir == 2) y++;
        if(dir == 3) x++;
        if(dir == 4) x--;
        Sleep (velocidad);
        }
    muerte2();
    system("pause>null");

     return 0;
}
