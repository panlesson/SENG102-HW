The project involves designing a system that manages various library resources such as books, magazines, and DVDs, each with its own borrowing rules and properties. The system will also handle user management for different library members like students, faculty, and the public, each having distinct borrowing privileges and durations. Additionally, the software will include functionalities to register library items, lend items out, accept returns, and track overdue items while accounting for the specific rules associated with each type of resource and member.


This project will serve as the software of a hypothetical self-service kiosk in a library.

Obviously we do not have access to neither the hardware of the said device or a library database, so the program is written to behave 'as if' it was actually installed within the place. While scanning items you will simply be asked to press a key to imitate scanning an item.

Here's the logic behind this program:
You enter an 8-digit number that is your Library Card Number.
If it starts with 1, the program assumes your member type as faculty.
If it starts with 2, the program assumes your member type as student.
If it starts with numbers other than 0, 1 or 2; the program assumes your member type as public.
The PIN is 6 digits.

Below is a list of members(Library Card Numbers and their PINs) stored within the program
11111111 111111
13582713 647711
15857585 411871
22222222 222222
28874049 183121
22977978 474728
20849848 885006
25254279 382309
23549160 758568
33333333 333333
75342860 415998
83759768 420476
79456279 714394
67865210 969520
45342115 203926
33213338 473405
74431645 661049
89317441 444053

Faculty members and students can borrow both books, magazines and DVDs.
Public members can borrow books and magazines.
Durations of items are different and are shown when checked out.
Program assumes that user has no overdue items or borrowed items at first.
Both borrowing and returning actively changes your items in the database, which you can then check with "1 - View Items" option.