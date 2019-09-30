#include <stdio.h>

#define FALSE   0
#define TRUE    (!FALSE)

int P, Q;

int PrisonCell[10009];
int PrisRelList[109];
int Used[109];

int MinCost;
int IterCount;

void Recurse( int CurrCost, int NumPris )
{
    if ( NumPris == Q )
    {
        IterCount++;
        /* printf("CurrCost: %d\n", CurrCost ); */

        if ( CurrCost < MinCost )
        {
            MinCost = CurrCost;
        }
    }
    else
    {
        int i, j;
        int Cell;
        int NewCost;

        for ( i = 0; i < Q; i++ )
        {
            if ( !Used[i] )
            {
                Used[i] = TRUE;
                Cell = PrisRelList[i];
                PrisonCell[Cell] = 0;

                NewCost = CurrCost;

                j = Cell;
                j++;

                while ( j < P )
                {
                    if ( PrisonCell[j] == 1 )
                    {
                        NewCost++;
                    }
                    else
                    {
                        break;
                    }
                    j++;
                }

                j = Cell;
                j--;

                while ( j >= 0 )
                {
                    if ( PrisonCell[j] == 1 )
                    {
                        NewCost++;
                    }
                    else
                    {
                        break;
                    }
                    j--;
                }

                Recurse( NewCost, NumPris + 1 );

                PrisonCell[Cell] = 1;
                Used[i] = FALSE;
            }
        }
    }
}

void Solve( void )
{
    int i;

    for ( i = 0; i < P; i++ )
    {
        PrisonCell[i] = 1;
    }

    for ( i = 0; i < Q; i++ )
    {
        Used[i] = FALSE;
    }

    MinCost = 110 * 10010 + 1;
    IterCount = 0;

    Recurse( 0, 0 );

    /* printf( "IterCount = %d\n", IterCount ); */
}

int main( void )
{
    int i, j, T;

    scanf( "%d", &T );

    for ( i = 1; i <= T; i++ )
    {
        scanf( "%d %d", &P, &Q );

        for ( j = 0; j < Q; j++ )
        {
            scanf( "%d", &PrisRelList[j] );
            PrisRelList[j]--;
        }

        Solve();

        printf( "Case #%d: %d\n", i, MinCost );
    }
}
