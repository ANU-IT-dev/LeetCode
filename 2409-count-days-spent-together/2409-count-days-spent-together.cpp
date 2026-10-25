class Solution {
public:
    int dayofyear(string date)
    {
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
         int days[] = {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
         for(int i=0; i<month-1; i++)
         {
            day+= days[i];

         }
         return day;
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

           int a1= dayofyear(arriveAlice);
           int b1 = dayofyear(leaveAlice);
           int a2 = dayofyear(arriveBob);
           int b2 = dayofyear(leaveBob);
            int start = max(a1,a2);
            int end= min(b1,b2);

            if(start>end) return 0;

            return end-start+1;
    }
};