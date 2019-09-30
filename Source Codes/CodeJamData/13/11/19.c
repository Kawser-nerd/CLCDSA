#include <stdio.h>

int quad(int a) {
    
    return a * a;
    
}

int main () {
    
    int t, radius, paint, c, to_fill, filled, turn, black;
    scanf("%d", &t);
    for (c = 1 ; t-- ; c++) {
        scanf("%d%d", &radius, &paint);
        black = 0;
        for (to_fill = 0, turn = 0 ; paint >= 0 ; to_fill++, turn = !turn) {
            if (turn) {
                paint -= quad(radius + to_fill) - quad(radius + to_fill - 1);
                if (paint >= 0)
                    black++;
            }
        }
        printf("Case #%d: %d\n", c, black);
    }
    
    return 0;
    
}
