#include<stdio.h>

FILE *ip, *op ;
int deckCount, indicesCount ;
int *indices, *deck ;

initDeck ()
{
int i ;
for ( i=0; i<deckCount; i++ )
    deck[i] = -1 ;
}

int main ()
{
    int testcases, i, j, tempCount, start, k ;
    
    ip = fopen ( "mtrapsmallip.in", "r" ) ;
    op = fopen ( "mtrapsmallop.txt", "w" ) ;
    
    fscanf ( ip, "%d", &testcases ) ;
    
    for ( i=0; i<testcases; i++ )
    {
        fscanf ( ip, "%d", &deckCount ) ;
        fscanf ( ip, "%d", &indicesCount ) ;
        
        indices = ( int *) malloc ( sizeof (int) * indicesCount ) ;
        
        for ( j=0; j<indicesCount; j++ )
                fscanf ( ip, "%d", &indices[j] ) ;
        
        deck = ( int * ) malloc ( sizeof (int)*deckCount ) ;
        
        initDeck () ;
        
        //printf ( "dc = %d\tic = %d", deckCount, indicesCount  ) ;
        for ( j=0; j<indicesCount; j++ )
                printf ( "\t%d", indices[j] ) ;
        
        start = 0;
        for ( j=1; j<=deckCount; j++ )
        {
            tempCount = 0;
            
            for ( k=start; ; k++ )
            {
                if ( k == deckCount )
                   k = 0;
                if ( deck[k] == -1  )
                {
                   tempCount++ ;
                   if ( tempCount == j )
                   {
                      deck[k] = j ;
                      //printf ( "\ndeck[%d]=%d", k, j ) ;
                      start = k+1 ;
                      break; 
                   }
                }
            }
        }
        
        fprintf ( op, "Case #%d: ", i+1 ) ;
        for ( j=0; j<indicesCount; j++ )
            fprintf ( op, "%d ", deck[indices[j]-1] ) ;
        fprintf ( op, "\n" ) ;
    }
     
    fclose ( ip ) ;    
    fclose ( op ) ;    
    return 0 ;
}
