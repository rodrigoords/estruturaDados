import java.util.List;
import java.util.ArrayList;

/**
 *  We have some cells and each cell have your own state, and this state can be 1 or 0, the rule is :
 *  If one cell has both of your neighbor  active(1) or inactive(0), in the next day the cell state need to change to inactive
 *  neither the cell state need to change to active.
 *  The cell value only change in the next day, to check the future cell value you need to use current neighbor cell value.
 *  The function will receive an array representing the cells initial states, and the number of days that system must calculate
 *  cells values. The output is the last day cells values.
 *
 *  Note: For the first and last cells that not have one neighbor, consider de missing neighbor inactive;
 *
 *  Example:
 *  input: [1,0,0,0,1,0,1], 5
 *  output: [0, 1, 0, 0, 0, 1, 0]
 */
public class State
{
  // METHOD SIGNATURE BEGINS, THIS METHOD IS REQUIRED
  public List<Integer> cellCompete(int[] states, int days)
  {

    List<Integer> integers = new ArrayList<>();
    // WRITE YOUR CODE HERE
    while(days > 0) { //don't check first day

      states = checkValue(0, states);

      days = days - 1;
    }

    for (int state : states) {
      integers.add(state);
    }

    return integers;

  }


  public int[] checkValue(int index, int[] cells) {

    int nextDayValue;

    if(index == 0) {
      if (cells[index+1] == 0){
        nextDayValue = 0;
      } else {
        nextDayValue = 1;
      }
      checkValue(index + 1, cells);
      cells[index] = nextDayValue;

    } else if (index == cells.length - 1){ //Last cell
      if(cells[index - 1] == 0) {
        cells[index] = 0;
      } else {
        cells[index] = 1;
      }

    } else {
      nextDayValue = cells[index-1] == cells[index+1] ? 0 : 1;
      checkValue(index + 1, cells);
      cells[index] = nextDayValue;

    }

      return cells;
  }

}

