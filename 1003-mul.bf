# Read two integers from stdin
>, >, <<

# Convert input to integers using atoi
+++++ +
[
    >----- ---   # Subtract ASCII '0' to convert to numerical value
    >----- ---
    <<-
]

# Multiply two integers
>[
    >[>+>+<<-]   # Multiply cell(0) and cell(1), store result in cell(2)
    [<+>-]
    <<-
]

# Separate two digits inputed
>[-]>+> >+++++ +++++<
[
    - >- [>>>]+++++ +++++<<+   # Separate the two digits
    [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<   # Move to the rightmost digit

# Convert result to ASCII (itoa)
<+++++ +
[
    >+++++ +++>   # Add ASCII '0' to convert back to ASCII
    [+++++ +++>]
    <[<]>-
]

# Print result with newline
>>[.<<]<[<<]>>.   # Print the result and newline
>>,.              # Print a comma

