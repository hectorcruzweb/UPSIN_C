#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#ifndef hrcp  
#define hrcp  
float hc_float(int digitos)
{
    if (digitos <= 0)
        return 0;
    /*
	  ****FUNCIÓN hc_float("Héctor Cruz Float"): permite capturar dígitos para un valor flotante. ****
	  Instrucciones para el "usuario programador"
	  Hace uso de las cabeceras:
	   -> #include<conio.h> para getch().
	   -> #include <stdlib.h> para atof().
	   -> Pide como argumento la cantidad de dígitos del número a capturar(digitos), 
	   el cual debe ser un valor entero (incluyendo decimales, 
	   el caracter "." es tomado en cuenta para el número final).
	  Forma de uso: 
	   -> Permite capturar solo un punto decimal, el cual antepone un "0" si el primer digito es el ".".
	   -> No permite terminar el número final si el último dígito capturado es un ".".
	   -> No permite terminar el número final si no se ha capturado nada.
	   -> Al capturar el número de dígitos que ha indicado el "usuario programador" se debe presionar "enter" para continuar.
	   -> Permite corregir los dígitos del número.
	   -> Retorna el valor capturado en forma "float".
	   -> La función valida el uso de los decimales para numeros de pocos dígitos
	   -> La función retorna un 0 al recibir un parametro de 0
  */
  
  	// Declaro las variables de la función
    int digitos_numero = digitos, x = 0;
    char caracter, digitos_string[digitos_numero] = { NULL };
    
    //comienzo el ciclo do wile, para el control de captura de dígitos
    do {
    	//pido el caracter al usuario por pantalla
        caracter = getch();
		
		//valido si el número de dígitos ingresados ya fueron capturados, 
		//si es asi solo se permite "enter para retornar el valor float" 
		//o el "return" para corregir algún dígito
        if (x == digitos) {
            if (caracter != 13 && caracter != 8) {
                caracter = NULL;
                continue;
            }
        }
        //valido si el último dígito es un (.) y el usuario a presionado "enter", lo cual no permite retornar el valor por capturar un número incompleto
        if (x > 0) {
            if (caracter == 13 && digitos_string[x - 1] == 46) {
                caracter = NULL;
                continue;
            }
        }
        else {
        	//valido si el usuario presiona "enter", pero aún no ha capturado nada. Lo cual, no permite retornar ningún valor por captura erronea
            if (caracter == 13) {
                caracter = NULL;
                continue;
            }
        }
        //Valido si el usuario ha capturado un dígito número(0-9) o punto(.).
        if ((caracter >= 48 && caracter <= 57) || caracter == 46) {
            //es caracter valido, es numero o un punto(.).
            //caracter_valido, variable de control para controlar si el dígito ingresado es válido para formar parte del número final
            int caracter_valido = 1;
            if (caracter == 46) {
            	//valido si el dígito capturado es un (.)
            	//hay que recorrer todo el arrglo del string "digitos_string", para revisar si el dígito (.) ha sido capturado antes.
                for (int y = 0; y < x; y++) {
                    if (digitos_string[y] != NULL) {
                        if (digitos_string[y] == 46) {
                            //se detecta que el (.) ya ha sido capturado anteriormente, lo cual la cariable 
							//"caracter_valido", indica que no debe formar parte del número final (se da el valor de 0 para indicar).
                            caracter_valido = 0;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
                //si el caracter (.) no ha sido ingresado antes en el número final, este se agrega al arreglo "digitos_string".
                if (caracter_valido == 1 && x == 0) {
                	//validamos si la función fue indicada capturar solo 1 dígito, para evitar que el usuario lo malgaste ingresando un (.)
                    if (digitos == 1) {
                        caracter = NULL;
                        continue;
                    }
                    //si el punto fue capturado como primer dígito, agregamos un "0" al string "digitos_string" y aumentamos en "1" a la varible de control del "digitos_string (x++)"
                    digitos_string[x] = 48;
                    printf("0");
                    x++;
                }
            }
            //si el dígito fue un numero(0-9) o un (.) válido, ingresamos el caracter al string "digitos_string".
            if (caracter_valido == 1) {
                digitos_string[x] = caracter;
                printf("%c", caracter);
                x++;
            }
        }
        else if (caracter == 8) {
        	//si el caracter capturado fue un "retorno", validamos que no se tome como válido para el primer dígito de "digitos_string".
            if (x > 0) {
            	//si es un retorno válido, limpiamos el último caracter del "digitos_string"
                x--;
                digitos_string[x] = NULL;
                printf("\b \b");
            }
        }
        //si el usuario ha presionado "enter", y cumple con las reglas de validación, puede retornar el valor como float
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
	  ****FUNCIÓN hc_int("Héctor Cruz Int"): permite capturar dígitos para un valor int. ****
	  Instrucciones para el "usuario programador"
	  Hace uso de las cabeceras:
	   -> #include<conio.h> para getch().
	   -> #include <stdlib.h> para atof().
	   -> Pide como argumento la cantidad de dígitos del número a capturar(digitos), 
	   el cual debe ser un valor entero.
	  Forma de uso: 
	   -> No permite terminar el número final si no se ha capturado nada.
	   -> Al capturar el número de dígitos que ha indicado el "usuario programador" se debe presionar "enter" para continuar.
	   -> Permite corregir los dígitos del número.
	   -> Retorna el valor capturado en forma "int".
	   -> La función retorna un 0 al recibir un parametro de 0
  */
  
  	// Declaro las variables de la función
    int digitos_numero = digitos, x = 0;
    char caracter, digitos_string[digitos_numero] = { NULL };
    //comienzo el ciclo do wile, para el control de captura de dígitos
    do {
    	//pido el caracter al usuario por pantalla
        caracter = getch();
		//valido si el número de dígitos ingresados ya fueron capturados, 
		//si es asi solo se permite "enter para retornar el valor int" 
		//o el "return" para corregir algún dígito
        if (x == digitos) {
            if (caracter != 13 && caracter != 8) {
                caracter = NULL;
                continue;
            }
        }
        //valido si el último dígito es un (.) y el usuario a presionado "enter", lo cual no permite retornar el valor por capturar un número incompleto
        if (x == 0) {
        	//valido si el usuario presiona "enter", pero aún no ha capturado nada. Lo cual, no permite retornar ningún valor por captura erronea
            if (caracter == 13) {
                caracter = NULL;
                continue;
            }
        }
        
        //Valido si el usuario ha capturado un dígito número(0-9) o punto(.).
        if (caracter >= 48 && caracter <= 57) {
            //es caracter valido, es numero o un punto(.).
            //caracter_valido, variable de control para controlar si el dígito ingresado es válido para formar parte del número final
            //si el dígito fue un numero(0-9), ingresamos el caracter al string "digitos_string".
                digitos_string[x] = caracter;
                printf("%c", caracter);
                x++;
        }
        else if (caracter == 8) {
        	//si el caracter capturado fue un "retorno", validamos que no se tome como válido para el primer dígito de "digitos_string".
            if (x > 0) {
            	//si es un retorno válido, limpiamos el último caracter del "digitos_string"
                x--;
                digitos_string[x] = NULL;
                printf("\b \b");
            }
        }
        //si el usuario ha presionado "enter", y cumple con las reglas de validación, puede retornar el valor como int
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

void hc_letters(int lon,char *pnom){
	 if (lon <= 0){
	 	return;
	 }
        //c>=65 && c<=90 may
        //c>=97 && c<=122 min
        //c==32 espace
        //c==164 ñ min
        //c==165 Ñ may
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
        //c==164 ñ min
        //c==165 Ñ may
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
#endif  
