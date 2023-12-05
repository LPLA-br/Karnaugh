/*########################################################
 *# Mapas de
 *# Karnaugh
 *# requisitos funcionais:
 *# 1.entrada com número de variáveis
 *# 2.entrada matriz unidimencional para S
 *#######################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h> //-lm
#include <string.h>


uint8_t* tratarArgumentoDois( int tamanho, char* string );
void mapa( uint8_t varnum, uint8_t* s );

// mapas NVariáveis=[2|3|4] S=1010100
int main( int argc, char* argv[] )
{
  if (argc >= 3)
  {
    if ( atoi(argv[1]) == 0 )
    {
      printf("FALHA: Argumento 1 inválido\n");
      exit(1);
    }

    if ( atoi(argv[1]) == 0 ) { printf("Argumento 2 inválido\n"); exit(1); }
    uint8_t varnum = atoi(argv[1]);

    //aplicação
    uint8_t* s = tratarArgumentoDois( varnum, argv[2] );
    if ( s != NULL)
    {
      mapa( varnum, s );
    }
    else
    {
      printf("tratarArgumentoDois() retornou NULL. ABORTADO\n");
      exit(1);
    }
  }
  else
  {
    exit(1);
  }
  exit(0);
}

uint8_t* tratarArgumentoDois( int varnum, char* string )
{

  if ( varnum < 2 || varnum > 3 )
  {
    printf("tratarArgumentoDois() falhou devido a número de variáveis inválido de: %i\n", varnum);
    return NULL;
  }

  switch ( strlen( string ) )
  {
    case 4:
      break;
    case 8:
      break;
    case 16:
      break;
    default:
      printf("string do segundo argumento do programa é inválida devido ao número de saidas S");
  }

  uint8_t* resultado = malloc( sizeof(uint8_t) * pow(2,varnum) );

  for ( uint8_t i = 0; i < pow(2,varnum); i++ )
  {
    if ( atoi( (string+i) ) == 0 )
    {
      printf("falha atoi(string+i) no loop iniciador de valores da matriz de retorno de tratarArgumentoDois()\n");
      free( resultado );
      return NULL;
    }
    else
    {
      *(resultado+i) = *(string+i);
    }
  }
  return resultado;
}

void mapa( uint8_t varnum, uint8_t* s )
{

  /* aproveitando o sistema posicional binário
   * SE o usuário inseriu a
   * entrou S na ordem certa :-)

   S 1010
   B 0101
   A 0011
     
   S 10101010
   C 01010101
   B 00110011
   A 00001111

   S 1010101010101010
   D 0101010101010101
   C 0011001100110011
   B 0000111100001111
   A 0000000011111111
   * */
  printf("Letras Minúsculas representam negações.\n");
  switch ( varnum )
  {
    case 2:
      printf(" Bb\n");
      printf("a%c%c\n", *(s+0x00),*(s+0x01));
      printf("A%c%c\n", *(s+0x02),*(s+0x03));
      break;
    case 3:
      printf(" bbBB\n");
      printf("a%c%c%c%c\n",*(s+0x00),*(s+0x01),*(s+0x03),*(s+0x02) );
      printf("A%c%c%c%c\n",*(s+0x04),*(s+0x05),*(s+0x07),*(s+0x06) );
      printf(" cCCc\n");
      break;
    case 4:
      printf(" ccCC\n");
      printf(" %c%c%c%cb\n",*(s+0x00),*(s+0x01),*(s+0x03),*(s+0x02));
      printf("a%c%c%c%cB\n",*(s+0x04),*(s+0x05),*(s+0x07),*(s+0x06));
      printf("A%c%c%c%cB\n",*(s+0b1100),*(s+0b1101),*(s+0b1111),*(s+0b1110));
      printf(" %c%c%c%cb\n",*(s+0b1000),*(s+0b1001),*(s+0b1011),*(s+0b1010));
      printf(" dDDd\n");
      break;
    default:
      printf("fail");
  }
  free(s);
}

