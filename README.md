# CSV-project

What we need to do 

first we will set up to open and close the file making sure that we check for proper open and closing 

implement f and r options first and ensure they work properly 

therefore to start only need to account

csv -f OR csv -r argc = 2 

argv[1] must equal -f or -r. We will work on -h later once we get -f and -r working the rest should flow from there. 

If -h is present that means the first line can be ignored as it is a header line and must be followed by a field name contained in quotes, will be followed
by either min, max, mean, or records. 

For min, max, mean, records if -h is used before then the field must be the Name of that field in the header. 

-h -records "Value"

max, min, mean, and records without -h need a NUMBER for the field, with the first being zero

Ex: 

1, 2, 3
4, 5, 6
7, 8, 9

csv -min 1
would yield 2. 

csv -max 0
would yield 7

csv -records 0 7

would give 7,8,9 since that's the only line with 7 in the 0 position.

char *strtok(char *str, const char *delim) <- I think this will be useful for us to figure this shit out. 