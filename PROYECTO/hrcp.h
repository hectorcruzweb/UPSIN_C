#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include <time.h>
#ifndef hrcp  
#define hrcp  

int last_y=0;
char texto[100]={'\0'};
char ti[100]={'\0'};

float hc_float(int digitos)
{
    if (digitos <= 0)
        return 0;
    /*
	  ****FUNCI?N hc_float("H?ctor Cruz Float"): permite capturar d?gitos para un valor flotante. ****
	  Instrucciones para el "usuario programador"
	  Hace uso de las cabeceras:
	   -> #include<conio.h> para getch().
	   -> #include <stdlib.h> para atof().
	   -> Pide como argumento la cantidad de d?gitos del n?mero a capturar(digitos), 
	   el cual debe ser un valor entero (incluyendo decimales, 
	   el caracter "." es tomado en cuenta para el n?mero final).
	  Forma de uso: 
	   -> Permite capturar solo un punto decimal, el cual antepone un "0" si el primer digito es el ".".
	   -> No permite terminar el n?mero final si el ?ltimo d?gito capturado es un ".".
	   -> No permite terminar el n?mero final si no se ha capturado nada.
	   -> Al capturar el n?mero de d?gitos que ha indicado el "usuario programador" se debe presionar "enter" para continuar.
	   -> Permite corregir los d?gitos del n?mero.
	   -> Retorna el valor capturado en forma "float".
	   -> La funci?n valida el uso de los decimales para numeros de pocos d?gitos
	   -> La funci?n retorna un 0 al recibir un parametro de 0
  */
  
  	// Declaro las variables de la funci?n
    int digitos_numero = digitos, x = 0;
    char caracter, digitos_string[digitos_numero] = { NULL };
    
    //comienzo el ciclo do wile, para el control de captura de d?gitos
    do {
    	//pido el caracter al usuario por pantalla
        caracter = getch();
		
		//valido si el n?mero de d?gitos ingresados ya fueron capturados, 
		//si es asi solo se permite "enter para retornar el valor float" 
		//o el "return" para corregir alg?n d?gito
        if (x == digitos) {
            if (caracter != 13 && caracter != 8) {
                caracter = NULL;
                continue;
            }
        }
        //valido si el ?ltimo d?gito es un (.) y el usuario a presionado "enter", lo cual no permite retornar el valor por capturar un n?mero incompleto
        if (x > 0) {
            if (caracter == 13 && digitos_string[x - 1] == 46) {
                caracter = NULL;
                continue;
            }
        }
        else {
        	//valido si el usuario presiona "enter", pero a?n no ha capturado nada. Lo cual, no permite retornar ning?n valor por captura erronea
            if (caracter == 13) {
                caracter = NULL;
                continue;
            }
        }
        //Valido si el usuario ha capturado un d?gito n?mero(0-9) o punto(.).
        if ((caracter >= 48 && caracter <= 57) || caracter == 46) {
            //es caracter valido, es numero o un punto(.).
            //caracter_valido, variable de control para controlar si el d?gito ingresado es v?lido para formar parte del n?mero final
            int caracter_valido = 1;
            if (caracter == 46) {
            	//valido si el d?gito capturado es un (.)
            	//hay que recorrer todo el arrglo del string "digitos_string", para revisar si el d?gito (.) ha sido capturado antes.
                for (int y = 0; y < x; y++) {
                    if (digitos_string[y] != NULL) {
                        if (digitos_string[y] == 46) {
                            //se detecta que el (.) ya ha sido capturado anteriormente, lo cual la cariable 
							//"caracter_valido", indica que no debe formar parte del n?mero final (se da el valor de 0 para indicar).
                            caracter_valido = 0;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
                //si el caracter (.) no ha sido ingresado antes en el n?mero final, este se agrega al arreglo "digitos_string".
                if (caracter_valido == 1 && x == 0) {
                	//validamos si la funci?n fue indicada capturar solo 1 d?gito, para evitar que el usuario lo malgaste ingresando un (.)
                    if (digitos == 1) {
                        caracter = NULL;
                        continue;
                    }
                    //si el punto fue capturado como primer d?gito, agregamos un "0" al string "digitos_string" y aumentamos en "1" a la varible de control del "digitos_string (x++)"
                    digitos_string[x] = 48;
                    printf("0");
                    x++;
                }
            }
            //si el d?gito fue un numero(0-9) o un (.) v?lido, ingresamos el caracter al string "digitos_string".
            if (caracter_valido == 1) {
                digitos_string[x] = caracter;
                printf("%c", caracter);
                x++;
            }
        }
        else if (caracter == 8) {
        	//si el caracter capturado fue un "retorno", validamos que no se tome como v?lido para el primer d?gito de "digitos_string".
            if (x > 0) {
            	//si es un retorno v?lido, limpiamos el ?ltimo caracter del "digitos_string"
                x--;
                digitos_string[x] = NULL;
                printf("\b \b");
            }
        }
        //si el usuario ha presionado "enter", y cumple con las reglas de validaci?n, puede retornar el valor como float
    } while (caracter != 13);
    //retornamos en valor en tipo "float".
    
   /* char *eptr;
    double result;
    return result = strtod(digitos_string, &eptr);
	*/	
    return atof(digitos_string);
}




int hc_int(int digitos)
{
    if (digitos <= 0)
        return 0;
    /*
	  ****FUNCI?N hc_int("H?ctor Cruz Int"): permite capturar d?gitos para un valor int. ****
	  Instrucciones para el "usuario programador"
	  Hace uso de las cabeceras:
	   -> #include<conio.h> para getch().
	   -> #include <stdlib.h> para atof().
	   -> Pide como argumento la cantidad de d?gitos del n?mero a capturar(digitos), 
	   el cual debe ser un valor entero.
	  Forma de uso: 
	   -> No permite terminar el n?mero final si no se ha capturado nada.
	   -> Al capturar el n?mero de d?gitos que ha indicado el "usuario programador" se debe presionar "enter" para continuar.
	   -> Permite corregir los d?gitos del n?mero.
	   -> Retorna el valor capturado en forma "int".
	   -> La funci?n retorna un 0 al recibir un parametro de 0
  */
  
  	// Declaro las variables de la funci?n
    int digitos_numero = digitos, x = 0;
    char caracter, digitos_string[digitos_numero] = { NULL };
    //comienzo el ciclo do wile, para el control de captura de d?gitos
    do {
    	//pido el caracter al usuario por pantalla
        caracter = getch();
		//valido si el n?mero de d?gitos ingresados ya fueron capturados, 
		//si es asi solo se permite "enter para retornar el valor int" 
		//o el "return" para corregir alg?n d?gito
        if (x == digitos) {
            if (caracter != 13 && caracter != 8) {
                caracter = NULL;
                continue;
            }
        }
        //valido si el ?ltimo d?gito es un (.) y el usuario a presionado "enter", lo cual no permite retornar el valor por capturar un n?mero incompleto
        if (x == 0) {
        	//valido si el usuario presiona "enter", pero a?n no ha capturado nada. Lo cual, no permite retornar ning?n valor por captura erronea
            if (caracter == 13) {
                caracter = NULL;
                continue;
            }
        }
        
        //Valido si el usuario ha capturado un d?gito n?mero(0-9) o punto(.).
        if (caracter >= 48 && caracter <= 57) {
            //es caracter valido, es numero o un punto(.).
            //caracter_valido, variable de control para controlar si el d?gito ingresado es v?lido para formar parte del n?mero final
            //si el d?gito fue un numero(0-9), ingresamos el caracter al string "digitos_string".
                digitos_string[x] = caracter;
                printf("%c", caracter);
                x++;
        }
        else if (caracter == 8) {
        	//si el caracter capturado fue un "retorno", validamos que no se tome como v?lido para el primer d?gito de "digitos_string".
            if (x > 0) {
            	//si es un retorno v?lido, limpiamos el ?ltimo caracter del "digitos_string"
                x--;
                digitos_string[x] = NULL;
                printf("\b \b");
            }
        }
        //si el usuario ha presionado "enter", y cumple con las reglas de validaci?n, puede retornar el valor como int
    } while (caracter != 13);
    //retornamos en valor en tipo "int".
    char *eptr;
    return atoi(digitos_string);
}




void valifec(char *pfecha){
	int dia=0, mes=0, anio=0, x=0, c=0, d=0, m=0, a=0, fec=0, bi=0;
	char diac[2], mesc[2], anioc[4];
	do{
		x=d=m=a=0;
		strcpy(diac,"  ");
		strcpy(mesc,"  ");
		strcpy(anioc,"    ");
		do{
			c=getch();
	    	if(c>=48 && c<=57){
				printf("%c",c);
    			if(x<2){
					diac[d]=c;
        			d++;
        		}
				else if (x<5){
					mesc[m]=c;
					m++;
				}
				else{
					anioc[a]=c;
					a++;
				}
				*(pfecha+x)=c;
    	    	x++;
	    	}
	    	if(x==2 || x==5){
				printf("/");
    	    	*(pfecha+x)='/';
        		x++;        
        	} 
			if(c==8 && x>0){
				x--;
	    		if(x==2){
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
	    			*(pfecha+x)=' ';
	    			d--;
	    		}
	    		else if(x<2){
					printf("\b \b");
					*(pfecha+x)=' ';
					d--;
				}
	    		else if(x==5){
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
					*(pfecha+x)=' ';
					m--;
	    		}
	    		else if(x<5){
					printf("\b \b");
					*(pfecha+x)=' ';
					m--;
				}
	    		else if(x>5){
					printf("\b \b");
	    			*(pfecha+x)=' ';
	    			a--;
	    		}
    		}            
		}while(x<10);
		dia=atoi(diac);
		mes=atoi(mesc);
		anio=atoi(anioc);
		bi=0;
		if(anio%4==0 && (anio%100!=0 || anio%400==0))
			bi++;
		if(dia<=31 && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=30 && (mes==4 || mes==6 || mes==9 || mes==11) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=28 && mes==2 && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia==29 && mes==2 && anio>=1900 && anio<=2050 && bi==1)
			fec=1;
		else
			for(int y=1;y<=10;y++)
				printf("\b \b");
	}while(fec!=1);
}

void hc_toupper(char *text){
	for (int i = 0; text[i]!='\0'; i++) {
      if(text[i] >= 'a' && text[i] <= 'z') {
         text[i] = text[i] -32;
      }
   }
}

void hc_letters(int lon,char *pnom){
	 if (lon <= 0){
	 	return;
	 }
        //c>=65 && c<=90 may
        //c>=97 && c<=122 min
        //c==32 espace
        //c==164 ? min
        //c==165 ? may
	int c=0, x=0;
    do{
		c=getch();
		if(c==39){
			c = NULL;
            continue;
		}
        if(c>=65 && c<=90 || c>=97 && c<=122 || c==32 || c==164 || c==165){
        	if(x<lon){
				printf("%c",c);
	            *(pnom+x)=c;
	            x++;
        	}
        }else if(c==8 && x>0){
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }else if (c == 13) {
        	if(x==0){
        		c = NULL;
                continue;
			}else{
				//trim los espacios en blanco
				int valido=0;
				for(int y=0;y<x;y++){
					if(*(pnom+y)!=32)
					valido=1;
				}
				if(valido==0){
	        		c = NULL;
	                continue;
				}
			}
        }
    }while(c!=13);
}


void hc_text(int lon,char *pnom){
	 if (lon <= 0){
	 	return;
	 }
        //c>=65 && c<=90 may
        //c>=97 && c<=122 min
        //c==32 espace
        //c==164 ? min
        //c==165 ? may
	int c=0, x=0;
	

    do{
		c=getch();
        if(c!=8 && c!=13){
        	if(x<lon){
				printf("%c",c);
	            *(pnom+x)=c;
	            x++;
        	}
        }else if(c==8 && x>0){
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }else if (c == 13) {
        	if(x==0){
        		c = NULL;
                continue;
			}else{
				//trim los espacios en blanco
				int valido=0;
				for(int y=0;y<x;y++){
					if(*(pnom+y)!=32)
					valido=1;
				}
				if(valido==0){
	        		c = NULL;
	                continue;
				}
			}
        }
    }while(c!=13);
}




void gotoxy(int X, int Y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=X;
	dwPos.Y=Y;
	SetConsoleCursorPosition(hcon,dwPos);
}

int r_number(int min,int max){
	return (rand() % (max - min + 1)) + min;
}


bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
    return is_exist;
}

void text_center(char *texto,int y){
	gotoxy(0,0);
	int s=strlen(texto);
	gotoxy(60-(s/2),y);
	printf(texto);
	gotoxy(60-(s/2)+s+2,y);
}

void text_x(char *texto,int x,int y){
	gotoxy(0,0);
	int s=strlen(texto);
	gotoxy(x-(s/2),y);
	printf(texto);
	gotoxy(x-(s/2)+s+2,y);
}


void main_s(){
	for(int x=0;x<120;x++){
		gotoxy(x,0);
		printf("*");
		gotoxy(x,1);
		printf("*");
		gotoxy(x,28);
		printf("*");
		gotoxy(x,29);
		printf("*");
	}
	
	for(int y=0;y<29;y++){
		gotoxy(0,y);
		printf("*");
		gotoxy(1,y);
		printf("*");
		gotoxy(119,y);
		printf("*");
		gotoxy(118,y);
		printf("*");
	}
}

int yes_no(char *question,int x,int y,int c,int ver_volver){
	int res=0;
    do {
    	printf("\b \b");
        //creamos el men?
        if(c==0){
	        text_x(("*** %s *** ",question),x,y);
	        text_x("(1) -- Si",x,y+2);
	        text_x("(2) -- No",x,y+4);
	        if(ver_volver==1){
			 text_x("(3) -- Volver",x,y+6);
			 text_x("ELIJA UNA OPCION:",x,y+8);	
			}else{
				text_x("ELIJA UNA OPCION:",x,y+6);		
			}
		}else{
			system("cls");
        	main_s();
			text_center((" *** %s *** ",question),10);
	        text_center("(1) -- Si",12);
	        text_center("(2) -- No",14);
	        if(ver_volver==1){
			text_center("(3) -- Volver",16);
	        text_center("ELIJA UNA OPCION:",18);	
			}else{
				text_center("ELIJA UNA OPCION:",16);	
			}
		}
        res = hc_int(1);
    } while ((ver_volver==1 && (res < 1  || res>3))|| (ver_volver==0 && (res < 1  || res>2)));
    return res;
}

void rm(char *filename){
	if(file_exists(filename)){
		if (remove(filename) != 0){
			printf("%s error\n",filename);
			exit(1);
		}	
	}	
}

bool error_torneo(){
	if(!file_exists("equipos.txt") || !file_exists("tipos.txt")|| !file_exists("jornadas.txt")|| !file_exists("juegos.txt")){
		//borramos todos los archivos y comenzamos nuevamente
		rm("equipos.txt");
		rm("tipos.txt");
		rm("jornadas.txt");
		rm("juegos.txt");
		system("cls");
		//Obligamos a crea un nuevo torneo
		main_s();
		text_center("<<< HA OCURRIDO UN ERROR, DEBE REINICIAR EL TORNEO >>>",14);
		getch();
		return true;
	}
	return false;
}

void date_add_days(int days, char* date_text){
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    /*
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    */                                                            
    tm.tm_mday += days;
    mktime(&tm);
    // Print the date in ISO-8601 format.                                                         
    strftime(date_text, 30, "%Y-%m-%d", &tm);
}



#endif  
