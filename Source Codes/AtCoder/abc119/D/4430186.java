import java.util.Arrays;
import java.util.OptionalLong;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int shrineCount = sc.nextInt();
        int templeCount = sc.nextInt();
        int questionCount = sc.nextInt();

        long[] shrinePositions = new long[shrineCount];
        for (int i = 0; i < shrineCount; i++) {
            shrinePositions[i] = sc.nextLong();
        }

        long[] templePositions = new long[templeCount];
        for (int i = 0; i < templeCount; i++) {
            templePositions[i] = sc.nextLong();
        }

        for (int i = 0; i < questionCount; i++) {
            long startPosition = sc.nextLong();
            System.out.println(findShortestDist(startPosition, shrinePositions, templePositions));
        }
    }

    private static long findShortestDist(long startPos, long[] shrPos, long[] tmplPos) {
        long[] nearestShringPos = getNearestPos(startPos, shrPos);
        long[] nearestTemplePos = getNearestPos(startPos, tmplPos);

        OptionalLong minWW = OptionalLong.empty();
        if (nearestShringPos[0] != 0 && nearestTemplePos[0] != 0) {
            minWW = OptionalLong.of(startPos - Math.min(nearestShringPos[0], nearestTemplePos[0]));
        }

        OptionalLong minEE = OptionalLong.empty();
        if (nearestShringPos[1] != 0 && nearestTemplePos[1] != 0) {
            minEE = OptionalLong.of(Math.max(nearestShringPos[1], nearestTemplePos[1]) - startPos);
        }

        OptionalLong minSETW = OptionalLong.empty();
        if (nearestShringPos[0] != 0 && nearestTemplePos[1] != 0) {
            minSETW = OptionalLong.of(((startPos - nearestShringPos[0]) * 2)
                    + (nearestTemplePos[1] - startPos));
        }

        OptionalLong minTESW = OptionalLong.empty();
        if (nearestShringPos[1] != 0 && nearestTemplePos[0] != 0) {
            minTESW = OptionalLong.of(((startPos - nearestTemplePos[0]) * 2)
                    + (nearestShringPos[1] - startPos));
        }

        OptionalLong minSWTE = OptionalLong.empty();
        if (nearestShringPos[1] != 0 && nearestTemplePos[0] != 0) {
            minSWTE = OptionalLong.of(((nearestShringPos[1] - startPos) * 2)
                    + (startPos - nearestTemplePos[0]));
        }

        OptionalLong minTWSE = OptionalLong.empty();
        if (nearestShringPos[0] != 0 && nearestTemplePos[1] != 0) {
            minTWSE = OptionalLong.of(((nearestTemplePos[1] - startPos) * 2)
                    + (startPos - nearestShringPos[0]));
        }

        return Stream.of(minWW, minEE, minSETW, minTESW, minSWTE, minTWSE)
                .filter(OptionalLong::isPresent)
                .mapToLong(OptionalLong::getAsLong)
                .min()
                .getAsLong();
    }

    private static long[] getNearestPos(long basePos, long[] positions) {
        long[] result = new long[2];
        int index = Arrays.binarySearch(positions, basePos);
        if (index < 0) {
            index = Math.abs(index + 1);
        }
        if (index == 0) {
            result[0] = 0;
            result[1] = positions[0];
        } else if (index >= positions.length) {
            result[0] = positions[positions.length - 1];
            result[1] = 0;
        } else if (positions[index] == basePos) {
            result[0] = result[1] = basePos;
        } else {
            result[0] = positions[index - 1];
            result[1] = positions[index];
        }
        return result;
    }
}