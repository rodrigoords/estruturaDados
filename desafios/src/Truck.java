import java.util.*;


/**
 * We have a truck and some packages to transport, so we need to make a program that:
 * Receive both, truck internal space representing by an integer and all packages we need
 * to delivery, representing by a List of Integers.
 * you need to find the 2 packages that space can be transported by your truck, considering the security space.
 * The rule is, ever reserve 30 of space on your truck for security propose.
 * Your truck can transport a maximum of 2 packages per delivery.
 * If more than one pair of packages can be transported, choose the biggest pair.
 *
 */
public class Truck {

  ArrayList<Integer> IDsOfPackages(int truckSpace,
                                   ArrayList<Integer> packagesSpace){

    int valueA = 0;
    int valueB = 0;

    for (int i = 0; i < packagesSpace.size(); i++) {
      for (int j = i + 1; j < packagesSpace.size(); j++) {
        if(packagesSpace.get(i) + packagesSpace.get(j) <= (truckSpace - 30 ) &&
        (packagesSpace.get(i) > packagesSpace.get(valueA) && packagesSpace.get(i) > packagesSpace.get(valueB) || packagesSpace.get(j) > packagesSpace.get(valueA) && packagesSpace.get(j) > packagesSpace.get(valueB) )) {
          valueA = i;
          valueB = j;
        }
      }
    }

    ArrayList<Integer> results = new ArrayList<>();

    results.add(valueA);
    results.add(valueB);
    return results;
  }

  ArrayList<Integer> IDsOfPackagesImproved(int truckSpace,
                                   ArrayList<Integer> packagesSpace){
    ArrayList<Integer> results = new ArrayList<>();

     Map<Integer, Integer> orginalIndexes = new HashMap<>();

    for (int i = 0; i < packagesSpace.size(); i++) {
      Integer integer = packagesSpace.get(i);
      orginalIndexes.put(integer, i);
    }

    packagesSpace.sort(Collections.reverseOrder()); //Sort array in ascend order

    for (int i = 0; i < packagesSpace.size(); i++) {
      for (int j = i + 1; j < packagesSpace.size(); j++) {
        if(packagesSpace.get(i) + packagesSpace.get(j) <= (truckSpace - 30 )) {
          results.add(orginalIndexes.get(packagesSpace.get(i)));
          results.add(orginalIndexes.get(packagesSpace.get(j)));
          return results;
        }
      }

    }

    return results;
  }

}
