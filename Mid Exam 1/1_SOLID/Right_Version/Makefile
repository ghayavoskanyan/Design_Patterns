CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: srp ocp lsp isp dip

srp: srp.cpp
	$(CXX) $(CXXFLAGS) srp.cpp -o srp_app.exe

ocp: ocp.cpp
	$(CXX) $(CXXFLAGS) ocp.cpp -o ocp_app.exe

lsp: lsp.cpp
	$(CXX) $(CXXFLAGS) lsp.cpp -o lsp_app.exe

isp: isp.cpp
	$(CXX) $(CXXFLAGS) isp.cpp -o isp_app.exe

dip: dip.cpp
	$(CXX) $(CXXFLAGS) dip.cpp -o dip_app.exe

clean:
	del /f /q *_app.exe 2>nul || rm -f *_app