:run.bat
:
:
:--------------------------------------- REQUIREMENT 3 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 3 WITH /s                                              
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp /s
:
:
:
:--------------------------------------- REQUIREMENT 3 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 3 WITHOUT /s                                              
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp
:
:
: --------------------------------------- requirement 5 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 5 WITH /d
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp /d

: --------------------------------------- requirement 5 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 5 WITHOUT /d
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp

: --------------------------------------- requirement 5 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 5 WITH /s and /d
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp /s /d

: --------------------------------------- requirement 6 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 6 WITH /s /d and /f with text search
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp /s /d /fclass

: --------------------------------------- requirement 6 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 6 WITH /s /d and /f with a different text search
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck *.h *.cpp /s /d /fstring

: --------------------------------------- requirement 7 -----------------------------------------------
echo               DEMONSTRATING REQUIREMENT 7 WITH ONLY PATH GIVEN AND NOTHING ELSE GIVEN
"Debug/Executive_Filecatalog.exe" Executive_Filecatalog\TestCheck

: --------------------------------------- requirement 7 -----------------------------------------------
echo              DEMONSTRATING REQUIREMENT 7 WITH NOTHING GIVEN
"Debug/Executive_Filecatalog.exe"
