import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class Solution {

  // Complete the isBalanced function below.
  static String isBalanced(String s) {

    Stack teste = new Stack();
    if(s.length() % 2 > 0)
      return "NO";

    Deque<String> brackets = new ArrayDeque<>();

    char[] chars = s.toCharArray();

    for (int i = 0; i < chars.length; i++) {

      char currentChar = s.charAt(i);

      if(needToPush(String.valueOf(currentChar))){
        brackets.push(String.valueOf(currentChar));
      } else {
        if(brackets.isEmpty())
          return "NO";
        String popString = brackets.pop();
        if(!isPair(popString, String.valueOf(currentChar)))
          return "NO";
      }

    }

    return brackets.isEmpty() ? "YES" : "NO";

  }

  private static boolean needToPush(String s){
    return "{".equals(s) || "[".equals(s) || "(".equals(s);
  }

  private static  boolean isPair(String a, String b){

    return "{".equals(a) && "}".equals(b) || "[".equals(a) && "]".equals(b) || "(".equals(a) && ")".equals(b);

  }

}
