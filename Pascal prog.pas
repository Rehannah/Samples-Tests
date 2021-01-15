Program test_marks(input, output);
uses wincrt;

Var
mark:real;

Begin  {Main begin}

     Writeln('Please enter a student"s test mark');
     Readln(mark);

Begin   {Begin1}

If mark < 60 then
    Writeln('Fail')
    Else
    Writeln('Pass')
End;
readkey;
End.       {end1}

