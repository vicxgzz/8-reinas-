 
# define  N  8
# include <stdio.h > 
# include <stdbool.h > 
  
				
void  imprimir( int tablero [N] [N])
{ 
    for ( int i = 0 ; i <N; i ++)
    { 
        for ( int j = 0 ; j <N; j ++)
            printf ( " % d " , tablero [i] [j]);
       printf("\n ");
    } 
} 
  
bool  casillaSeg( int tablero [N] [N], int fila, int columna)
{ 
    int i, j;
   for (i = 0 ; i <columna; i ++) 
        if (tablero [fila] [i])
            return  false;
  
  for (i = fila, j = columna; i>= 0 && j>= 0 ; i--, j--)
        if (tablero [i] [j])
            return  false ;
  
  for (i = fila, j = columna; j>= 0 && i <N; i ++, j--)
        if (tablero [i] [j])
            return  false ;
            return  true ;
} 
  

bool  resolverNReinas ( int tablero [N] [N], int columna)
{ 

   if (columna>= N)
        return  true;
  

    for ( int i = 0 ; i <N; i ++)
    { 
 
        if ( casillaSeg (tablero, i, columna))
        { 

            tablero [i] [columna] = 1 ;
  
        
            if ( resolverNReinas (tablero, columna + 1 ))
                return true;
  
          
            tablero [i] [columna] = 0 ;
        } 
    } 
  

   return  false ;
} 
  

bool  resultado (){ int tablero [N] [N] =  {{  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0},
                                            {  0 , 0 , 0 , 0 ,0 , 0, 0 ,0}, }; 
  
    if ( resolverNReinas (tablero, 0 ) == false )
    { 
      return false ;
    } 
  
    imprimir (tablero);
    return  true;
} 
  
 
int  main ()
{ 
    resultado ();
    return  0 ;
} 
