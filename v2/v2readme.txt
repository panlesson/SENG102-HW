The project involves designing a system that manages various library resources such as books, magazines, and DVDs, each with its own borrowing rules and properties. The system will also handle user management for different library members like students, faculty, and the public, each having distinct borrowing privileges and durations. Additionally, the software will include functionalities to register library items, lend items out, accept returns, and track overdue items while accounting for the specific rules associated with each type of resource and member.


This project will serve as the software of a hypothetical self-service kiosk in a library.

Obviously we do not have access to neither the hardware of the said device or a library database, so the program is written to behave 'as if' it was actually installed within the place. Which means that during the login phase, the program will simply accept whatever string of numbers you entered as long as the lengths match, for demonstration purposes, and while scanning items you will be asked to press a key to imitate scanning an item.

Here's the logic behind this program:
You enter an 8-digit number that is your Library Card Number.
If it starts with 1, the program assumes your member type as faculty.
If it starts with 2, the program assumes your member type as student.
If it starts with numbers other than 0, 1 or 2; the program assumes your member type as public.

The PIN is 6 digits.

Faculty members and students can borrow both books, magazines and DVDs.
Public members can borrow books and magazines.
Durations of items are different and are shown when checked out.
Program assumes that user has no overdue items or borrowed items at first.
Both borrowing and returning actively changes your items in the database, which you can then check with "1 - View Items" option.