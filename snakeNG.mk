##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=snakeNG
ConfigurationName      :=Debug
WorkspacePath          := "/home/jesper/private/workspace"
ProjectPath            := "/home/jesper/private/snakeNG"
IntermediateDirectory  :=./debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jesper Larsen
Date                   :=17/10/16
CodeLitePath           :="/home/jesper/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="snakeNG.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++ -g
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_LoadMedia.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_OnEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_OnInit.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_OnLoop.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_OnRender.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./debug || $(MakeDirCommand) ./debug


$(IntermediateDirectory)/.d:
	@test -d ./debug || $(MakeDirCommand) ./debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_LoadMedia.cpp$(ObjectSuffix): src/LoadMedia.cpp $(IntermediateDirectory)/src_LoadMedia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/LoadMedia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LoadMedia.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LoadMedia.cpp$(DependSuffix): src/LoadMedia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LoadMedia.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LoadMedia.cpp$(DependSuffix) -MM "src/LoadMedia.cpp"

$(IntermediateDirectory)/src_LoadMedia.cpp$(PreprocessSuffix): src/LoadMedia.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LoadMedia.cpp$(PreprocessSuffix) "src/LoadMedia.cpp"

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_OnEvent.cpp$(ObjectSuffix): src/OnEvent.cpp $(IntermediateDirectory)/src_OnEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/OnEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_OnEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_OnEvent.cpp$(DependSuffix): src/OnEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_OnEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_OnEvent.cpp$(DependSuffix) -MM "src/OnEvent.cpp"

$(IntermediateDirectory)/src_OnEvent.cpp$(PreprocessSuffix): src/OnEvent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_OnEvent.cpp$(PreprocessSuffix) "src/OnEvent.cpp"

$(IntermediateDirectory)/src_OnInit.cpp$(ObjectSuffix): src/OnInit.cpp $(IntermediateDirectory)/src_OnInit.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/OnInit.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_OnInit.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_OnInit.cpp$(DependSuffix): src/OnInit.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_OnInit.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_OnInit.cpp$(DependSuffix) -MM "src/OnInit.cpp"

$(IntermediateDirectory)/src_OnInit.cpp$(PreprocessSuffix): src/OnInit.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_OnInit.cpp$(PreprocessSuffix) "src/OnInit.cpp"

$(IntermediateDirectory)/src_OnLoop.cpp$(ObjectSuffix): src/OnLoop.cpp $(IntermediateDirectory)/src_OnLoop.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/OnLoop.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_OnLoop.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_OnLoop.cpp$(DependSuffix): src/OnLoop.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_OnLoop.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_OnLoop.cpp$(DependSuffix) -MM "src/OnLoop.cpp"

$(IntermediateDirectory)/src_OnLoop.cpp$(PreprocessSuffix): src/OnLoop.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_OnLoop.cpp$(PreprocessSuffix) "src/OnLoop.cpp"

$(IntermediateDirectory)/src_OnRender.cpp$(ObjectSuffix): src/OnRender.cpp $(IntermediateDirectory)/src_OnRender.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jesper/private/snakeNG/src/OnRender.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_OnRender.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_OnRender.cpp$(DependSuffix): src/OnRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_OnRender.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_OnRender.cpp$(DependSuffix) -MM "src/OnRender.cpp"

$(IntermediateDirectory)/src_OnRender.cpp$(PreprocessSuffix): src/OnRender.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_OnRender.cpp$(PreprocessSuffix) "src/OnRender.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./debug/


