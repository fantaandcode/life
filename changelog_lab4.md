Changelog - 2/27/2018

squares

- In the initialization of arr, changed malloc(n) to malloc(n-1), otherwise it would have one too many spots.
- Changed fillsquares to return the array and added an assignment when the function is called in main.
- Added free(arr) to free the memory at the very end.

strings
- Added free(s) to the end of make_copy.