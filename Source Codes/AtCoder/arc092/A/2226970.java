import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<Grid> gridList = new ArrayList<>();

        int n = in.nextInt();
        for(int i = 0; i < n; i++) {
            gridList.add(new Grid(Color.RED, in.nextInt(), in.nextInt()));
        }
        for(int i = 0; i < n; i++) {
            gridList.add(new Grid(Color.BLUE, in.nextInt(), in.nextInt()));
        }

        gridList.sort(Comparator.comparing(Grid::getX).thenComparing(Grid::getColor));
        List<Grid> list = new ArrayList<>();
        int ans = 0;
        for (Grid grid : gridList) {
            if(grid.color == Color.RED) {
                list.add(grid);
            } else {
                Optional<Grid> maxGrid = list.stream()
                        .filter(g -> g.getY() < grid.getY())
                        .max(Comparator.comparing(Grid::getY));
                if(maxGrid.isPresent()) {
                    ans++;
                    list.remove(maxGrid.get());
                }
            }
        }
        System.out.println(ans);
    }
}

class Grid {

    Color color;
    int x;
    int y;

    public Grid(Color color, int x, int y) {
        this.color = color;
        this.x = x;
        this.y = y;
    }
    public Color getColor() { return this.color; }
    public int getX() { return this.x; }
    public int getY() { return this.y; }

    public String toString(){
        return String.format(color + " \t" + x + ", " + y);
    }
}

enum Color {
    BLUE,
    RED
}