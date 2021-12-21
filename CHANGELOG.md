# Change Log

**2.5.1**
- Remove '<>' auto completion

**2.5.0**
- Add relatives

**2.4.3**
- Fixed numerics

**2.4.2**
- Fixed numerics

**2.4.1**
> URCL
- +&BITS Macro's (&BITS, &MSB, $SMSB, &MAX, &SMAX, &UHALF, &LHALF)
- +Numeric's now support relatives +/-1234

> Tuk
- +For loop snippet
- +Auto closing brakets

**2.4.0**
- Transparent logo icon
- Add code example image to README
- Add .simple.urcl has very little error detection and works better as an injected language into b code. Supports B style variables

**2.3.3**
- Fixed links

**2.3.2**
- Add README.md
- Add CHANGELOG.md
- Add Icon image

**2.3.1**
- Add all header snippets
- Remove comment snippets
- Fix POP snippet
- Remove KeyBindings

> URCL
- Mess with comments again :|
- Macro's can sort of accept block comments
- Add Char opperand to Macro's

> B
- No longer mark white space as invalid
- Remove control statement Do
- Add -> operators

**2.3.0**
- Add support for Tuk language (For Tukeque)
- Remove underlines from everything when using different themes (URCL)
- Remove commas from 4 opperand instructions (DBLE_BGE)
- Strings now use double quotes " instead of single quotes '
- Fix comments

**2.2.0**
- Add snippets for instructions, comments, RUN and BITS (Ctrl+Space)
- Add KeyBinds for comments
- Add /**/ as block comments under language-configs
- Fix 4 opperand instructions (DBLE_BGE) not highlighting

**2.1.0**
> URCL
- Every instruction now has the correct opperand setup
- Remove commas from all instructions except 4 opperand instructions (DBLE_BGE)
- Highlights incorrect opperand types when in the wrong place
- .labels now try to highlight every character up to a whitespace instead of stopping at an invalid character
- Add 4 opperand DBLE_BGE
- Add SP and PC as registers
- Memmory increased from 16 to 66536
- Seperated ports from numerics
- Opperands no longer try matching across whitespaces
- Add single character char opperand
- Remove deprecated instructions: BRA, BZR, BNR
- Change ports from constant.numeric to support.class

> B
- Increase error detection on control statements
- Increase error detection on data types (auto)
- Increase error detection on operators
- Increase error detection on commas
- Variables can no longer start with numeric's
- Functions can no longer start with numeric's
- Functions can now have operators in front

**2.0.2**
- Try to fix comments when URCL is injected into B code

**2.0.1**
- Registers colour corrected fromr support.class to variable
- Registers increased from 15 to 65536
- Memmory increased from 15 to 16

**2.0.0**
- Publish to market place
- Add B language
- URCL code injection into B
- Rewrite URCL
- Break comments

**1.1.0**
- Add multiline block-comments
- Add #Memory and $Registers
- Macro's can have multiple arguments
- Add header arguments

**1.0.0**
- Initial release
- URCL syntax highlighting only
- No B or Tuk code
- No snippets