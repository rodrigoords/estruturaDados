public class Main {

  public static void main(String[] args){
    final Main main = new Main();
    System.out.println("number of ways: " + main.numWays(999999999));
  }

  public int numWays(int number){
    if(number == 0 || number ==1)
      return 1;

    int beforeOne = 1;
    int beforeTwo = 1;
    int current = 0;

    for (int i = 2; i <= number; i++) {

      current = beforeTwo + beforeOne;

      beforeTwo = beforeOne;
      beforeOne = current;

    }

    return current;
  }

}
