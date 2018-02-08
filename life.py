from screen import Screen
from argument_parsing import getArgs

from time import time

def main():
    S = Screen(**getArgs())
    S.run()
if __name__ == "__main__":
    main()
