import java.util.*;

public class Energy {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    StringBuilder out = new StringBuilder();
    int numCases = in.nextInt();
    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
      out.append(String.format("Case #%d: ", caseNum));
      
      long maxEnergy = in.nextLong();
      long currentEnergy = maxEnergy;
      long regen = in.nextLong();
      int numEvents = in.nextInt();
      long[] values = new long[numEvents];
      for (int i = 0; i < values.length; ++i)
        values[i] = in.nextLong();
      
      int curEvent = 0;
      /*
        Algo:
        For the current event we are on, look ahead to see how far away the next event with a larger value is.
        Suppose it is D away.
        Then leave Math.max(E - R*D, 0) energy at the end of this current event.
        If there is nothing else larger, then leave 0 energy at the end of this current event.
        
        What about after we've used all our energy? I think it will still work out, because the amount left will be less than E - R*D, so we won't
        spend any additional energy.  Though I'll need to check to make sure that the amount I leave is less than or equal to what we currently have
      */
      
      // not sure if n^2 ok...n = 10000, n^2 = 100 000 000, per 100 cases..., = 10^10... 10 billion... maybe okay in 8 min.
      long totalValue = 0;
      
      while (curEvent != numEvents) {
        // find the next event which has a higher value than cur event
        // currently, n^2 algo.
        int nextEvent = curEvent+1;
        while (nextEvent != numEvents && values[nextEvent] <= values[curEvent])
          ++nextEvent;
        if (nextEvent == numEvents) {
          // nothing else has a higher value.
          // leave 0 energy.
          totalValue += values[curEvent] * currentEnergy;
          currentEnergy = 0;
        } else {
          // nextEvent has higher value.
          // it is nextEvent-curEvent distance away
          // we should leave Math.max(E - R*D, 0) energy
          long energyToLeave = Math.max(maxEnergy - regen*(nextEvent - curEvent), 0L);
          if (energyToLeave >= currentEnergy) {
            // we need to leave more energy than we have.  this means we should spend 0 energy at this event
            // so nothing to be done here
          } else {
            // we have more energy than we need to leave, spend it
            long energyToSpend = currentEnergy - energyToLeave;
            totalValue += values[curEvent] * energyToSpend;
            currentEnergy = energyToLeave;
          }
        }
        currentEnergy += regen;
        currentEnergy = Math.min(currentEnergy, maxEnergy);
        ++curEvent;
      }
      out.append(totalValue);
      out.append('\n');
    }
    System.out.print(out);
  }
}