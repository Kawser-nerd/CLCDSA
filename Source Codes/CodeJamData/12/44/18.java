import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Max Loewenthal
 */
public class D {
  public static class Coordinate {
    int x;
    int y;

    public Coordinate(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public class Room {
    int start;
    int end;
    int height;
    private boolean _terminal;

    public Set<Integer> getEscapes() {
      return escapes;
    }

    public Set<Integer> getForbiddens() {
      return forbiddens;
    }

    private Set<Integer> escapes = new HashSet<Integer>();
    private Set<Integer> forbiddens = new HashSet<Integer>();

    public Room(int height, int start, int end, boolean terminal) {
      this.start = start;
      this.end = end;
      this.height = height;
      _terminal = terminal;

      for (int i = start; i < end + 1; i++) {
        if (passable[i][height + 1]) {
          if (Boolean.TRUE.equals(reachableFrom[i][height+1])) {
            escapes.add(i);
          }
          else {
            forbiddens.add(i);
          }
        }
      }
    }

    public int length() {
      return end - start + 1;
    }


    public boolean canEscape(int i) {
      int x = 0;
      if (i>=0) {
        x = Math.min(start+i, end);
      }
      else {
        x = Math.max(start, end + i + 1);
      }

      return escapes.contains(x);
    }


    public boolean isForbidden(int i) {
      int x;
      if (i>=0) {
        x = Math.min(start+i, end);
      }
      else {
        x = Math.max(start, end + i + 1);
      }

      return forbiddens.contains(x);
    }
  }

  int rows;
  int columns;
  boolean[][] passable;

  Coordinate[] caves = new Coordinate[10];


  public void solve(Scanner input, StringBuilder buffer) {
    buffer.append("\n");
    rows = input.nextInt();
    columns = input.nextInt();
    passable = new boolean[columns][rows];
    input.nextLine();

    for (int i = 0; i <rows; i++) {
      String line = input.nextLine();
      for (int j = 0; j < columns; j++) {
        char space = line.charAt(j);


        if (Character.isDigit(space)) {
          passable[j][i] = true;
          caves[Integer.parseInt("" + space)] = new Coordinate(j, i);
        }
        else if (space == '.') {
          passable[j][i] = true;
        }
        else {
          passable[j][i] = false;
        }
      }
    }


    for (int i = 0; i < caves.length; i++) {
      Coordinate cave = caves[i];

      if (cave != null) {
        processCave(i, cave, buffer);
      }
    }

  }

  private void processCave(int caveNumber, Coordinate cave, StringBuilder buffer) {
    buffer.append(caveNumber).append(": ");
    Set<Room> rooms = new HashSet<Room>();

    Finder finder = new Finder(cave.x, cave.y);

    buffer.append(finder.doIt(rooms)).append(" ");

    Room terminalRoom = finder.terminalRoom();

      if (!processRooms(rooms, terminalRoom)) {
        buffer.append("Unlucky\n");
      }
    else {
    buffer.append("Lucky\n");
      }
  }

  private boolean processRooms(Set<Room> rooms, Room terminalRoom) {
    boolean progress;
    do {
      progress = false;
      for (Room room: rooms) {
        if (eliminatable(room, rooms, terminalRoom)) {
          rooms.remove(room);
          progress = true;
          break;
        }
      }
    } while(rooms.size() > 0 && progress);

    return rooms.isEmpty();
  }

  private Room findRoom(Room fromRoom, Set<Room> allRooms, int i) {
    int y = fromRoom.height + 1;
    int x = (i<0)?Math.max(fromRoom.start, fromRoom.end + i + 1):Math.min(fromRoom.start + i, fromRoom.end);

    for (Room room: allRooms) {
      if (room.height == y && x>=room.start && x<=room.end) {
        return room;
      }
    }

    return null;
  }

  public boolean eliminatable(Room fromRoom, Set<Room> allRooms, Room terminalRoom) {
    for (int i = 0; i < columns; i++) {
      if (fromRoom.canEscape(i)) {
        boolean result = true;
        for (Room room:allRooms) {
          if (room.isForbidden(i)) {
            result = false; break;
          }
        }
        result = result && !terminalRoom.isForbidden(i);

        if (result) {
          Room newRoom = findRoom(fromRoom, allRooms, i);
          if (newRoom != null) {
            allRooms.add(newRoom);
          }

          return result;
        }
      }
    }

    for (int i = -1; i >= -columns; i--) {
      if (fromRoom.canEscape(i)) {
        boolean result = true;
        for (Room room:allRooms) {
          if (room.isForbidden(i)) {
            result = false; break;
          }
        }
        result = result && !terminalRoom.isForbidden(i);

        if (result) {
          Room newRoom = findRoom(fromRoom, allRooms, i);
          if (newRoom != null) {
            allRooms.add(newRoom);
          }

          return result;
        }
      }
    }

    return false;
  }

  private Boolean[][] reachableFrom;

  public class Finder {
    private final int _targetX;
    private final int _targetY;
    private Room _terminalRoom;

    public Finder(int targetX, int targetY) {
      _targetX = targetX;
      _targetY = targetY;
      reachableFrom = new Boolean[columns][rows];

      for (int i=0; i<columns; i++) {
        for (int j=0; j<rows; j++) {
          reachableFrom[i][j] =null;
        }
      }

      reachableFrom[_targetX][_targetY] = true;
    }

    public Room terminalRoom() {
      return _terminalRoom;
    }

    public int doIt(Set<Room> rooms) {
      int result = 0;
      for (int y = _targetY ; y >= 0; y--) {
      for (int x = 0; x < columns; x++) {
          process(x,y);
        }
      }

      for (int y = rows -1 ; y >= 0 ; y--) {
        int start = -1;
        for (int x = 0; x < columns; x++) {
          boolean reachable = reachableFrom[x][y] != null && reachableFrom[x][y];

          if (reachable) {
            result = result + 1;
          }

          if (reachable && start == -1) {
            start = x;
          }

          if (!reachable && start > -1) {
            if (y == _targetY) {
              _terminalRoom = new Room(y, start, x-1, true);
            }
            else {
              rooms.add(new Room(y, start, x-1, false));
            }

            start = -1;
          }
        }
      }

      return result;
    }

    public boolean process(int x, int y) {
      if (!passable[x][y]) {
        return false;
      }

      boolean result = false;
      if (reachableFrom[x][y] != null) {
        result = reachableFrom[x][y];
      }


      int current = x;
      int end = x - 1;

      while(passable[current][y]) {
        result = result || Boolean.TRUE.equals(reachableFrom[current][y]) || process(current, y+1);

        current = current + 1;
      }

      for (int i = x; i < current; i++) {
        reachableFrom[i][y] = result;
      }

      return result;
    }



  }



  public static void main(String[] args) {
    try {
      InputStream input = System.in;
      OutputStream output = System.out;

      if (args.length > 0) {
        input = new FileInputStream(new File(args[0]));
      }

      if (args.length > 1) {
        File outputFile = new File(args[1]);

        if (outputFile.exists()) {
          throw new Exception("Output file already exists");
        }

        output = new FileOutputStream(new File(args[1]));
      }

      Scanner scanner = new Scanner(input);
      PrintWriter writer = new PrintWriter(output);

      int count = scanner.nextInt();
      scanner.nextLine();

      for (int i = 0; i < count; i++) {
        StringBuilder result = new StringBuilder();
        D a = new D();

        a.solve(scanner, result);


        writer.print("Case #" + (i + 1) + ": " + result.toString());
      }

      writer.close();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }
}
