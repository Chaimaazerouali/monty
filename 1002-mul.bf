++++[>++++[>+++<-]<-]   # Set cell(2) to the ASCII value of '0' (48 / 0x30)
,>,>                    # Read two numbers into cell(0) and cell(1)
[<-<->>-]               # Convert cell(0) and cell(1) to numerical values (subtract ASCII '0')
<<                      # Move to cell(0)
[                       # Multiplication loop
    >                   # Move to cell(1)
    [>+>+<<-]           # Multiply cell(0) and cell(1), store result in cell(2)
    >>                  # Move to cell(2)
    [<<+>>-]            # Move result back to cell(1)
    <<<-                # Decrement cell(0)
]
>[-]<                   # Set cell(1) to 0 (reset counter, we are in cell 0 here)
++++[>++++[>+++<-]<-]   # Add '0' to cell(2), converting the result back to ASCII
>>.                     # Print the result (go to cell(2) and print)

