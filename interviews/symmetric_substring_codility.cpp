#include <iostream>
#include <string>
using namespace std;

int solve(string s)
{
  int left = 0, right = 0, maxCount = 0, openCount = 0, closeCount = 0, quesCount = 0;

  while (right < s.length())
  {
    if (s[right] == '<')
    {
      if (closeCount > 0)
      {
        evaluate();
        left = right;
        openCount = 0;
        closeCount = 0;
        quesCount = 0;
      }
      else
      {
        right++;
        openCount++;
      }
    }
    else if (s[right] == '>')
    {
      closeCount++;
      right++;
    }
    else
    {
      quesCount++;
      right++;
    }
  }
}

int evaluate()
{
}

int main()
{
}

// [<<????>>>><<<]

// [<<><<<>>>]

// what is the symmetric condition?

// left is always equal to right and follow the open close tag trend

// // If OB is encountered then -> keep going right
//  right++

// // once a question mark is encountered -> it could be a open/ close tag

// // if CB is encountered -> definitely implies a close tag
//  any OB after this means series can't continue further

// 1. Pick the potential substrings

//    //check when the series is ending

//   Left_pointer = 0, Right_Pointer =0, MAX_LENGTH =0, Series_Length = 0, OB_count =0, CB_Count=0,
//   QM_Befor_Last_OB=0, QM_After_First_CB=0, QM_Between_Both = 0

// // keep left pointer at 0 and increment the right pointer -> this is checking of one potential substring

//   // if we find it then send it to evaluate_max_length function

// //increment the left pointer to next Right Pointer -> evaluate again same process

// 2. Potential Substring Method

// while(Right_Pointer < s.length())
// {

//   // basic condition on based of input
//   if (s[Right_Pointer] == '<')
//   {

//     // if CB_Count is > 0 => closed bracket has already occured so a definite open bracket after that would terminate //a series

//     if (CB_Count > 0 && Series_Length > 0)
//     {
//       Left_pointer = Right_Pointer;

//       // evaluate the substring till now and set the MAX_LENGTH
//       Evauate(OB_count, CB_Count, QM_Befor_Last_OB, QM_Between_Both, QM_After_First_CB)

//           // reset the Series_Length field = 0, OB_count=0, CB_Count =0, QM_Count =0
//           Series_Length = 0;
//       OB_count = 0;
//       CB_Count = 0;
//       QM_Befor_Last_OB = 0;
//       QM_Between_Both = 0;
//       QM_After_First_CB = 0;
//     }
//     else
//     {

//       // if this is not a first OB then transfer QM_Mid to QM_Before

//       if (OB_count > 0 && QM_Between_Both > 0)
//       {
//         QM_Befor_Last_OB += QM_Between_Both;
//         QM_Between_Both = 0;
//       }

//       Series_Length++;
//       OB_count++;
//       Right_Pointer++;
//     }
//   }
//   else if (s[Right_Pointer] == '>')
//   {
//     CB_Count++;
//     Series_Length++;
//     Right_Pointer++;
//   }
//   else
//   {
//     if (OB_count == 0 && CB_Count == 0)
//     {
//       QM_Befor_Last_OB++;
//     }
//     else if (OB_count > 0 && CB_Count == 0)
//     {
//       QM_Between_Both++;
//     }
//     else if (CB_Count > 0)
//     {
//       QM_After_First_CB;
//     }

//     Series_Length++;
//     Right_Pointer++;
//   }
// }

// // assuming all the other values are known to this function , can be added as input param later
// Evauate()
// {

//   // OB_count = no of open brackets
//   // CB_Count = no of close brackets
//   // QM_Befor_Last_OB = no of question marks before the last open brackets => it can only be open
//   // QM_Between_Both = no of question marks between last Open brakcet and first close bracket => it can become both
//   // QM_After_First_CB = no of question marks after first close bracket => it can only be close

//   formula

//       int Actual_Open_Brakcet_Count = OB_count + QM_Befor_Last_OB;
//   int Actual_Close_Bracket_Count = CB_Count + QM_After_First_CB;

//   if (Actual_Close_Bracket_Count == 0 || Actual_Open_Brakcet_Count == 0)
//   {
//     // don't update max length
//     return;
//   }

//   int result = min(Actual_Open_Brakcet_Count, Actual_Close_Bracket_Count) + QM_Between_Both / 2;

//   MAX_LENGTH = max(result * 2, MAX_LENGTH);
// }

// [><<??>?<>] = 6

// // first iteration while loop

// Left_pointer = 0, Right_Pointer =0

// CB_Count = 1, Series_Length =1, Right_Pointer = 1

// // next iteration

// Evaluate -> OB_count = 0,CB_Count = 1 , MAX_LENGTH =0

// Reset everything to 0;

// // evaluate same pointer Left_pointer = 1, Right_Pointer =1

// Right_Pointer = 2, Series_Length = 1, OB_count = 1

//                                       // next iteration
//                                       Right_Pointer = 3,
//                    Series_Length = 2, OB_count = 2

//                                       // next iteration
//                                       QM_Between_Both = 1,
//                    Right_Pointer = 4, Series_Length = 3, OB_count = 2,

//                    // next iteration
//     QM_Between_Both = 2, Right_Pointer = 5, Series_Length = 4, OB_count = 2

//                                                                // next iteration
//                                                                QM_Between_Both = 2,
//                    Right_Pointer = 6, Series_Length = 5, OB_count = 2, CB_Count = 1

//                                                                        // next iteration
//                                                                        QM_Between_Both = 2,
//                    Right_Pointer = 7, Series_Length = 6, OB_count = 2, CB_Count = 1, QM_After_First_CB = 1

//                                                                                      // next iteration
//                                                                                      Evaluate function call with above values

//                                                                                          Actual_Open_Brakcet_Count = 2 + 0 Actual_Close_Bracket_Count = 1 + 1

//                                                                                                                                                         Min(Actual_Open_Brakcet_Count, Actual_Close_Bracket_Count) = 2

//                                                                                      result = Min + QM_Between_Both / 2 = 2 + 2 / 2 = 3 MAX_LENGTH = max(result * 2, MAX_LENGTH)
