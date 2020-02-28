import java.util.*;
import java.util.stream.Collectors;

public class Main {

  public static void main(String[] args){

    final Main main = new Main();

    List<int[]> points = new ArrayList<>();
    points.add(new int[]{-2,4});
    points.add(new int[]{0,-2});
    points.add(new int[]{-1,0});
    points.add(new int[]{3,5});
    points.add(new int[]{-2,-3});
    points.add(new int[]{3,2});


    final List<int[]> nearPoints = main.findPoints(points, 2);

    nearPoints.forEach(e -> System.out.println("["+  e[0] + "," + e[1] +"]"));

  }


  public List<int[]> findPoints(List<int[]> values, int quantity){
    int[] pointA = new int[]{0,0};

    SortedMap<Double, int[]> pointsByDistance = new TreeMap<>();

    for (int[] point : values) {
      pointsByDistance.put(findDistance(pointA, point), point);
    }

    final Collection<int[]> points = pointsByDistance.values();

    return points.stream()
            .limit(quantity)
            .collect(Collectors.toList());

  }

  private double findDistance(int[] pointA, int[] pointB){
    return Math.sqrt( Math.pow(pointA[0] + pointA[1], 2) + Math.pow(pointB[0] + pointB[1], 2));
  }
}
