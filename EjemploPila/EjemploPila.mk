##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=EjemploPila
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/Users/sergio/Documents/EEDD/EEDD
ProjectPath            :=/Users/sergio/Documents/EEDD/EEDD/EjemploPila
IntermediateDirectory  :=../build-$(ConfigurationName)/EjemploPila
OutDir                 :=../build-$(ConfigurationName)/EjemploPila
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sergio Picazo
Date                   :=19/10/2020
CodeLitePath           :="/Users/sergio/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/EjemploPila/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/EjemploPila/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/EjemploPila"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/EjemploPila"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/EjemploPila/.d:
	@mkdir -p "../build-$(ConfigurationName)/EjemploPila"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(ObjectSuffix): Nodo.cpp ../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sergio/Documents/EEDD/EEDD/EjemploPila/Nodo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Nodo.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(DependSuffix): Nodo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(DependSuffix) -MM Nodo.cpp

../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(PreprocessSuffix): Nodo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/EjemploPila/Nodo.cpp$(PreprocessSuffix) Nodo.cpp

../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(ObjectSuffix): Pila.cpp ../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sergio/Documents/EEDD/EEDD/EjemploPila/Pila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pila.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(DependSuffix): Pila.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(DependSuffix) -MM Pila.cpp

../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(PreprocessSuffix): Pila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/EjemploPila/Pila.cpp$(PreprocessSuffix) Pila.cpp

../build-$(ConfigurationName)/EjemploPila/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/EjemploPila/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sergio/Documents/EEDD/EEDD/EjemploPila/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/EjemploPila/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/EjemploPila/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/EjemploPila/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/EjemploPila/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/EjemploPila/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/EjemploPila//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


