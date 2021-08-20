#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente;
  }

  Lexico::Lexico(){
    ind= 0;
  }

  string Lexico::tipoAcad(int tipo){
         string cad= "";

         switch (tipo){
           case TipoSimbolo::IDENTIFICADOR:
                cad= "Identificador";
                break;

           case TipoSimbolo::OPADIC:
                cad= "Op. Adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "Op. Multiplicacion";
                break;

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;

           case TipoSimbolo::ENTERO:
                cad= "Entero";
                break;

           case TipoSimbolo::REAL:
                cad= "Real";
                break;

         }

         return cad;
  }

  void Lexico::entrada(string fuente){
       ind= 0;
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){

    estado=0;
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
      c= sigCaracter();

      switch (estado){
        case 0:
             if ( c >= '0' && c <= '9')
                 sigEstado(1);

             else if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
                 sigEstado(4);

             else if( c == '$')
                 aceptacion(5);
          break;
        case 1:
              if ( c >= '0' && c <= '9')
              {
                  sigEstado(1);
              }
              else
              {
                  if( c == '.')
                    sigEstado(2);

                  else{
                      continua = false;
                      retroceso();
                  }
              }
          break;
        case 2:
              if ( c >= '0' && c <= '9')
              {
                  sigEstado(3);
              }
              else{
                  continua = false;
                  retroceso();
              }
          break;
        case 3:
              if ( c >= '0' && c <= '9')
              {
                  sigEstado(3);
              }
              else{
                  continua = false;
                  retroceso();
              }
          break;
        case 4:
              if( ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) /*|| (c >= '0' && c <= '9')*/ )
                  sigEstado(4);
              else{
                  continua = false;
                  retroceso();
              }
          break;

      }

   }
    //Fin del Automata

      switch (estado){

        case 1:
              tipo=TipoSimbolo::ENTERO;
              break;
        case 2:
              tipo= TipoSimbolo::IDENTIFICADOR;
              break;
        case 3:
              tipo= TipoSimbolo::REAL;
              break;
        case 4:
              tipo= TipoSimbolo::IDENTIFICADOR;
              break;
        default:
              tipo= TipoSimbolo::ERROR;
      }

    return tipo;
}

 char Lexico::sigCaracter(){
      if (terminado()) return '$';

      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){
       this->estado= estado;
       simbolo+= c;
  }

  void Lexico::aceptacion(int estado){
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){
        return isalpha(c) || c=='_';
   }


   bool Lexico::esDigito(char c){
        return isdigit(c);
   }

   bool Lexico::esEspacio(char c){
        return c== ' ' || c== '\t';
   }


   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
