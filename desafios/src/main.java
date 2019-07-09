import java.util.ArrayList;

public class main {
  public static void main(String arg[]) {
    // Cells problem
    State state = new State();

    int[] cells = {1,0,0,0,1,0,1};

    System.out.println(state.cellCompete(cells,1));


    // Truck problem
    Truck truck = new Truck();


    ArrayList<Integer> arrayList = new ArrayList<>();

    arrayList.add(35);
    arrayList.add(42);
    arrayList.add(10);
    arrayList.add(27);
    arrayList.add(23);
    arrayList.add(24);
    arrayList.add(25);
    arrayList.add(30);
    arrayList.add(33);
    arrayList.add(34);
    arrayList.add(42);
    arrayList.add(43);
    arrayList.add(44);
    arrayList.add(55);
    arrayList.add(56);
    arrayList.add(67);
    arrayList.add(68);
    arrayList.add(69);
    arrayList.add(90);
    arrayList.add(13);
    arrayList.add(64);
    arrayList.add(45);
    arrayList.add(21);
    arrayList.add(14);
    arrayList.add(5);


    System.out.println("IDsOfPackages");
    long startTime = System.nanoTime();
    ArrayList<Integer> integers = truck.IDsOfPackages(31, arrayList);
    long finishTime = System.nanoTime();

    System.out.println(integers);

    long duration = (finishTime - startTime);
    System.out.println(duration);




    System.out.println("IDsOfPackagesImproved");
    long startTimeImproved = System.nanoTime();
    ArrayList<Integer> integersImproved = truck.IDsOfPackagesImproved(31, arrayList);
    long finishTimeImproved = System.nanoTime();

    System.out.println(integersImproved);

    long durationImproved = (finishTimeImproved - startTimeImproved);
    System.out.println(durationImproved);
  }
}
