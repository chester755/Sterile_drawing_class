/*************************************************************************
Version history: v1.0.0 Added few plotting function which includes far over 
near standard drawing funciton FoverNDraw which allows u to draw it in 
different parameter space. Matrix drawing function which allows you to draw
the color matrix plots for systematic uncertainty study. ErrorBandPlot 
standard upper and lower error band plots. Also the Errorband comparison 
function which allows you to compare the detail difference between the upper
and lower error band.
v2.0.0 Added a new ploting function which automatically re-arrange the
legends' location called GSPlot (Amazing).
v2.0.1 Fixed a small bug with GSPlot, I have to add an addtional contradictory
options. If I set user range for any axis, I wouldn't be able to set log 
scale for that axis. Therefore this option has to seperate it. i.e op=0 
give you max and min range for y, op=1 give you log scale plot.
v2.0.2 You probably will be surprise by the fact that I don't have a simple
TH2D plot function give you just the plane 2*2 plots. Stay happy, it's here
now. SimplePlot, your best option (or not).
v2.1.0 A maj0r updates for GSPlots, allow users to choose the draw & style 
option.
v3.0.0 After a heart-breaking experience, I decided to update this class to
include the standard plotting class, which have both top and bot plots.

Next update: So I intend to add more function to this GSPlot function which 
hopefully automatically draw a second axis based on the current information
they have.
Also the old function probably can be re-written in a much simpler manner.
Last update time: 27/07/2015
*************************************************************************/
#include <string>
#include <sstream>
#include "TString.h"
#include "TH2.h"
#include "TH2D.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TDirectory.h"
#include "TMarker.h"
#include "SterileDraw.h"
#include "TGaxis.h"
#include "TLine.h"
#include "/Users/Chester/work/c_class/Sterile_Check/SterileCheck.h"
#include "/Users/Chester/work/c_class/Sterile_Text/SterileText.h"

ClassImp(SterileDraw);

using namespace std;

void SterileDraw::SetMatrixValue(Double_t minimum_value, Double_t maximum_value){
  ZMinValue=minimum_value;
  ZMaxValue=maximum_value;
};

SterileDraw::SterileDraw (TString opt, TString name, TH2D* hist){
  
  const Int_t NRGBs = 5;
  const Int_t NCont = 104;
  Double_t gctstops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t gctred[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t gctgreen[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t gctblue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  Double_t minimum=hist->GetMinimum();

  if(opt=="COLZ2441"){
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
    gStyle->SetOptStat(0000);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{41}(eV^{2})");
    hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("COLZ");
    c->Update();
  }  
  if(opt=="CONT12441"){
    Double_t contarray[1];
    contarray [0]=minimum+4.61;
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    hist->SetContour(1,contarray);
    gStyle->SetOptStat(0000);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{41}(eV^{2})");
    //hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("CONT3");
    c->Update();
  }  
  if(opt=="CONT1COLZ2441" || opt=="COLZCONT12441"){
    TH2D* hist_clone=(TH2D*)hist->Clone("hist_clone");
    Double_t contarray[1];
    contarray [0]=minimum+4.61;
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    hist->SetContour(1,contarray);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{41}(eV^{2})");
    //hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("CONT3");
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
    gStyle->SetOptStat(0000);
    gPad->SetLogx();
    gPad->SetLogy();
    hist_clone->SetXTitle("sin^{2}(2#theta_{24})");
    hist_clone->SetYTitle("#Delta m^{2}_{41}(eV^{2})");
    hist_clone->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist_clone->Draw("COLZSAME");
    c->Update();
  }
  if(opt=="COLZ2443"){
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
    gStyle->SetOptStat(0000);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{43}(eV^{2})");
    hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("COLZ");
    c->Update();
  }  
  if(opt=="CONT12443"){
    Double_t contarray[1];
    contarray [0]=minimum+4.61;
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    hist->SetContour(1,contarray);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{43}(eV^{2})");
    //hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("CONT3");
    c->Update();
  }  
  if(opt=="CONT1COLZ2443" || opt=="COLZCONT12443"){
    TH2D* hist_clone=(TH2D*)hist->Clone("hist_clone");
    Double_t contarray[1];
    contarray [0]=minimum+4.61;
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    hist->SetContour(1,contarray);
    gPad->SetLogx();
    gPad->SetLogy();
    hist->SetXTitle("sin^{2}(2#theta_{24})");
    hist->SetYTitle("#Delta m^{2}_{43}(eV^{2})");
    //hist->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist->Draw("CONT3");
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
    gStyle->SetOptStat(0000);
    gPad->SetLogx();
    gPad->SetLogy();
    hist_clone->SetXTitle("sin^{2}(2#theta_{24})");
    hist_clone->SetYTitle("#Delta m^{2}_{43}(eV^{2})");
    hist_clone->GetZaxis()->SetRangeUser(minimum-15,minimum+15);
    hist_clone->Draw("COLZSAME");
    c->Update();
  }
};

///////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\ This effective draw the matrix
TCanvas* SterileDraw::MatrixDraw(TString name, TH2D* hist_matrix, Bool_t SetZRangeManually){
  const Int_t NRGBs = 5;
  const Int_t NCont = 104;
  Double_t gctstops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t gctred[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t gctgreen[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t gctblue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TCanvas* c = new TCanvas(name, name, 1600, 1200);
  TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
  gStyle->SetNumberContours(NCont);
  gStyle->SetOptStat(0000);
  gPad->SetBottomMargin(0.15);
  gPad->SetTopMargin(0.05);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.05);
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  hist_matrix->SetTitle("");
  hist_matrix->GetXaxis()->SetRangeUser(0,40);
  hist_matrix->GetYaxis()->SetRangeUser(0,40);
  hist_matrix->GetXaxis()->CenterTitle();
  hist_matrix->GetYaxis()->CenterTitle();
  hist_matrix->SetXTitle("Reconstructed Energy (GeV)");
  hist_matrix->SetYTitle("Reconstructed Energy (GeV)");
  
  Double_t maximum=hist_matrix->GetMaximum();
  Double_t minimum=hist_matrix->GetMinimum();
  if(SetZRangeManually){
    hist_matrix->GetZaxis()->SetRangeUser(ZMinValue,ZMaxValue);
  }
  
  else{
    if(minimum<0){
      hist_matrix->GetZaxis()->SetRangeUser((minimum*1.1),(maximum*1.1));
    }
    else{
      hist_matrix->GetZaxis()->SetRangeUser((minimum*0.9),(maximum*1.1));
    }
  }
  hist_matrix->Draw("COLZ");
  //c->Update();
  return c;
};

TCanvas* SterileDraw::FANMatrixDraw(TString name, TH2D* hist_matrix, Bool_t SetZRangeManually){
  const Int_t NRGBs = 5;
  const Int_t NCont = 104;
  Double_t gctstops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t gctred[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t gctgreen[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t gctblue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TCanvas* c = new TCanvas(name, name, 1600, 1200);
  TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
  gStyle->SetNumberContours(NCont);
  gStyle->SetOptStat(0000);
  gPad->SetBottomMargin(0.15);
  gPad->SetTopMargin(0.05);
  gPad->SetLeftMargin(0.08);
  gPad->SetRightMargin(0.12);
  gPad->RedrawAxis();
  gPad->SetTicks(1,1);
  hist_matrix->SetTitle("");
  //hist_matrix->GetXaxis()->SetRangeUser(0,40);
  //hist_matrix->GetYaxis()->SetRangeUser(0,40);
  hist_matrix->GetXaxis()->SetTitleSize(0.06);
  hist_matrix->GetXaxis()->SetTitleOffset(0.8);
  hist_matrix->GetYaxis()->SetTitleSize(0.06);
  hist_matrix->GetYaxis()->SetTitleOffset(0.5);
  hist_matrix->GetXaxis()->CenterTitle();
  hist_matrix->GetYaxis()->CenterTitle();
  hist_matrix->SetXTitle("Dual Sepctrum Bins");
  hist_matrix->SetYTitle("Dual Spectrum Bins");
  
  Double_t maximum=hist_matrix->GetMaximum();
  Double_t minimum=hist_matrix->GetMinimum();
  if(SetZRangeManually){
    hist_matrix->GetZaxis()->SetRangeUser(ZMinValue,ZMaxValue);
  }
  
  else{
    if(minimum<0){
      hist_matrix->GetZaxis()->SetRangeUser((minimum*1.1),(maximum*1.1));
    }
    else{
      hist_matrix->GetZaxis()->SetRangeUser((minimum*0.9),(maximum*1.1));
    }
  }
  hist_matrix->Draw("COLZ");
  //c->Update();
  return c;
};


TCanvas* SterileDraw::FoverNDraw(TString name, Double_t value, TH1D* FoN){
  if(value==0){
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    FoN->SetXTitle("Reconstructed Energy (GeV)");
    FoN->Draw();
    return c;
  }
  else if(value>0){
    TCanvas* c = new TCanvas(name, name, 1200, 600);
    FoN->GetXaxis()->SetRangeUser(0,value);
    FoN->SetXTitle("Reconstructed Energy (GeV)");
    FoN->Draw();
    return c;
  }
  else{    
    std::cout << "Selected value aren't valid please try again." << endl;
    TCanvas* c = new TCanvas();
    return c;
  }
};

///////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\ This is drawing the error band
TCanvas* SterileDraw::ErrorBandPlot(TString name, TH1D* histp, TH1D* histm, Double_t XRange){
  TH1D* histp_area=(TH1D*)histp->Clone();
  TH1D* histm_area=(TH1D*)histm->Clone();
  TH1D* histp_line=(TH1D*)histp->Clone();
  TH1D* histm_line=(TH1D*)histm->Clone();
  Double_t maxp=histp_area->GetMaximum();  
  Double_t maxm=histm_area->GetMaximum();
  Double_t minp=histp_area->GetMinimum();
  Double_t minm=histm_area->GetMinimum();
  Double_t max,min;

  if(minp>minm){
    min=minm;
  }
  else{
    min=minp;
  }
  if(maxp>maxm){
    max=maxp;
  }
  else{
    max=maxm;
  }

  Int_t nbin=histp_area->GetNbinsX();
  Double_t range=histp_area->GetBinLowEdge(nbin);
  range = XRange;
  //  histp_area->SetTitle(name+"_Error");
  histp_area->SetXTitle("Reconstruct Energy (GeV)");
  histp_area->SetYTitle("#frac{N_{Shifted}-N_{Nominal}}{N_{Nominal}}");  
  TCanvas *plot=new TCanvas(name,name,1600,800);
  histp_area->GetYaxis()->SetRangeUser(min*1.2,max*1.2);
  histp_area->GetXaxis()->SetRangeUser(0,range); 
  histp_area->SetFillColor(kCyan-10);
  histm_area->SetFillColor(kCyan-10);
  gStyle->SetOptStat(0);
  histp_line->SetLineColor(kBlue);
  histp_line->SetLineWidth(4);
  histm_line->SetLineColor(kRed);
  histm_line->SetLineWidth(4);
  histp_area->Draw();
  histm_area->Draw("SAME");
  gPad->SetTicks(1,1);
  gPad->RedrawAxis();
  histp_line->Draw("SAME");
  histm_line->Draw("SAME");
  
  return plot;
  
};

TCanvas* SterileDraw::ErrorBandPlot(TString name, TH1D* histp, TH1D* histm){
  TH1D* histp_area=(TH1D*)histp->Clone();
  TH1D* histm_area=(TH1D*)histm->Clone();
  TH1D* histp_line=(TH1D*)histp->Clone();
  TH1D* histm_line=(TH1D*)histm->Clone();
  Double_t maxp=histp_area->GetMaximum();  
  Double_t maxm=histm_area->GetMaximum();
  Double_t minp=histp_area->GetMinimum();
  Double_t minm=histm_area->GetMinimum();
  Double_t max,min;

  if(minp>minm){
    min=minm;
  }
  else{
    min=minp;
  }
  if(maxp>maxm){
    max=maxp;
  }
  else{
    max=maxm;
  }

  Int_t nbin=histp_area->GetNbinsX();
  Double_t range=histp_area->GetBinLowEdge(nbin);
  //  histp_area->SetTitle(name+"_Error");
  histp_area->SetXTitle("Reconstruct Energy (GeV)");
  histp_area->SetYTitle("#frac{N_{Shifted}-N_{Nominal}}{N_{Nominal}}");  
  TCanvas *plot=new TCanvas(name,name,1600,800);
  histp_area->GetYaxis()->SetRangeUser(min*1.2,max*1.2);
  histp_area->GetXaxis()->SetRangeUser(0,range); 
  histp_area->SetFillColor(kCyan-10);
  histm_area->SetFillColor(kCyan-10);
  gStyle->SetOptStat(0);
  histp_line->SetLineColor(kBlue);
  histp_line->SetLineWidth(4);
  histm_line->SetLineColor(kRed);
  histm_line->SetLineWidth(4);
  histp_area->Draw();
  histm_area->Draw("SAME");
  gPad->SetTicks(1,1);
  gPad->RedrawAxis();
  histp_line->Draw("SAME");
  histm_line->Draw("SAME");
  
  return plot;
  
};

TCanvas* SterileDraw::ErrorBandPlotComp(TString name, Double_t shift, TH1D* histp, TH1D* histm){
  stringstream ss;
  ss << shift;
  TString shiftname=ss.str()+" Shift";
  TH1D* histp_copy=(TH1D*)histp->Clone();
  TH1D* histm_copy=(TH1D*)histm->Clone();  
  histm_copy->Scale(-1);
  Double_t max=histp_copy->GetMaximum();
  Double_t min=histm_copy->GetMinimum();
  Int_t nbin=histp_copy->GetNbinsX();
  Double_t range=histp_copy->GetBinLowEdge(nbin);
  histp_copy->SetTitle(name+"_Error");
  histp_copy->SetXTitle("Reconstruct Energy (GeV)");
  histp_copy->SetYTitle("#frac{N_{Shifted}-N_{Nominal}}{N_{Nominal}}");  
  TCanvas *plot=new TCanvas(name,name,1600,800);
  histp_copy->GetYaxis()->SetRangeUser(min*0.9995,max*1.0005);
  histp_copy->GetXaxis()->SetRangeUser(0,range);
  histp_copy->SetMarkerStyle(2);
  histp_copy->SetMarkerSize(2);
  histp_copy->SetMarkerColor(kBlue);
  histm_copy->SetMarkerStyle(2);
  histm_copy->SetMarkerSize(2);
  histm_copy->SetMarkerColor(kRed);
  gStyle->SetOptStat(0);
  histp_copy->Draw("P0");
  histm_copy->Draw("P0SAME");
  TLegend* leg=new TLegend(0.1,0.8,0.4,0.9);
  leg->SetHeader("Error Comparison");
  leg->AddEntry(histp_copy,name+" "+shiftname);
  leg->AddEntry(histm_copy,name+" -"+shiftname);
  leg->Draw("SAME");
  return plot;
};

///////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\

//This function is designed to be the ultimate plotting function, which will be the best plotting function in the entire history of the Root (not true)
//It means it will automately adjust the box location base on the date points and make sure the legend will not overlap with data regardless of the situation.
//It then will plot the histogram with it's set name. i.e. this is sick ok?.

TCanvas* SterileDraw::GSPlot(vector<TH1D*> hists, TString CanvasName, Int_t draw_options, Int_t style_options){

    
  SterileCheck* check = new SterileCheck();
  Double_t Max=check->FindMaximum(hists);
  Double_t Min=check->FindMinimum(hists);
  Int_t Nhists=hists.size();
  //Int_t NbinsX=hists.at(0)->GetNbinsX();
  vector<TH1D*> hists_cp;
  vector<TString> hists_name;
  vector<Double_t> X;
  vector<Double_t> Y;
  vector<Double_t> X1;
  vector<Double_t> Y1;
  vector<Double_t> X2;
  vector<Double_t> Y2;
  vector<Double_t> X3;
  vector<Double_t> Y3;
  vector<Double_t> X4;
  vector<Double_t> Y4;
  Double_t sec1=0;
  Double_t sec2=0;
  Double_t sec3=0;
  Double_t sec4=0;
  Int_t secnumber=-1;
    
  if(style_options==0){
    for(Int_t i=0; i<Nhists; ++i){
      TH1D* h;
      h=hists.at(i);
      if(i < 9){
	h->SetLineColor(i+1);
      }
      else{
      h->SetLineColor(i+11);
      }
      
      hists_cp.push_back(h);
    }
  }
  else if(style_options==1){
    Int_t histsNo=0;
    Int_t colorNo=0;
    while(histsNo<Nhists){
      TH1D* h1=hists.at(histsNo);
      TH1D* h2=hists.at(histsNo+1);
      h1->SetLineColor(colorNo);
      h2->SetLineColor(colorNo);
      h1->SetLineStyle(1);
      h2->SetLineStyle(2);
      histsNo+=2;
      colorNo+=1;
    }
  }

  TCanvas* plot=new TCanvas(CanvasName,CanvasName,1600,1200);
  if(draw_options==0){
    hists.at(0)->GetYaxis()->SetRangeUser(Min,Max);
  }
  else if(draw_options==1){
    gPad->SetLogy();
  }
  for(Int_t i=0; i<Nhists; ++i){
    TString tmp=hists.at(i)->GetName();
    hists_name.push_back(tmp);
    if(i==0){
      hists_cp.at(i)->Draw();
    }
    else{
      hists_cp.at(i)->Draw("SAME");
    }
  }
  gStyle->SetOptStat(0);
  gPad->SetTicks(1,1);

  gPad->Update();
  gStyle->SetOptStat(0);
  
  Double_t Xmax=gPad->GetUxmax();
  cout << "Maximum pad value" << Xmax<< endl;
  Double_t XHmax=(Xmax/2);
  Double_t YHmax=((Max-Min)/2);
  Int_t Xmaxbin=(hists_cp.at(0)->GetXaxis()->FindFixBin(Xmax)-1);
  cout << "Bin numbers" << Xmaxbin << endl;
  for(Int_t i=0; i<Xmaxbin; ++i){
    for(Int_t k=0; k<Nhists; ++k){
      Double_t xcoord=hists.at(k)->GetBinCenter(i);
      Double_t ycoord=hists.at(k)->GetBinContent(i);
      X.push_back(xcoord);
      Y.push_back(ycoord);
      cout << "X and Y coordinates are " << xcoord << " " << ycoord << endl;
      if(xcoord<XHmax && ycoord<YHmax){
	sec3++;  	
	X3.push_back(xcoord);
	Y3.push_back(ycoord);
      }
      else if(xcoord<XHmax && ycoord>YHmax){
	sec1++;	
	X1.push_back(xcoord);
	Y1.push_back(ycoord);
      }
      else if(xcoord>XHmax && ycoord>YHmax){
	sec2++;       
	X2.push_back(xcoord);
	Y2.push_back(ycoord);
      }
      else if(xcoord>XHmax && ycoord<YHmax){
	sec4++;
	X4.push_back(xcoord);
	Y4.push_back(ycoord);
      }
      cout << sec1 << " " << sec2 << " " << sec3 << " " << sec4 << endl;
    }
  }
  
  vector<Double_t> seccount;
  seccount.push_back(sec1);
  seccount.push_back(sec2);
  seccount.push_back(sec3);
  seccount.push_back(sec4);
  Double_t mi=sec1;
  cout << " Value of mi " << mi << endl;
  secnumber=0;
  
  for(Int_t i=1; i<4; ++i){
    cout << i << " section has this number of events " << seccount.at(i) << endl;
    if(mi>seccount.at(i)){
      mi=seccount.at(i);
      secnumber=(i);
    }
  }
  
  
  cout << secnumber+1 << "Section Number" << endl;
  
  //For each section I will try 4 different locations, it should exclude most of the regions!!!
  //It is stored as four vectors contains four x,y coordinates for legend coordinates (x1,y1) (x2,y2)
  Double_t y_length=0.03*Nhists;
  Int_t SNum=4;
  Int_t Tp=4;
  Double_t x1[SNum][Tp];
  Double_t x2[SNum][Tp];
  Double_t y1[SNum][Tp];
  Double_t y2[SNum][Tp];
  
  for(Int_t i=0; i<4; ++i){
    for(Int_t j=0; j<4; ++j){

      if(i==0 || i==2){
	
	if(j==0 || j==2){
	  x1[i][j]=0.1;
	  x2[i][j]=0.4;
	}

	else if(j==1 || j==3){
	  x1[i][j]=0.2;
	  x2[i][j]=0.5;
	}
      }

      else if(i==1 || i==3){

	if(j==0 || j==2){
	  x1[i][j]=0.6;
	  x2[i][j]=0.9;
	}
	
	else if(j==1 || j==3){
	  x1[i][j]=0.5;
	  x2[i][j]=0.8;
	}
      }
    }
  }

  for(Int_t i=0; i<4; ++i){
    for(Int_t j=0; j<4; ++j){

      if(i==0 || i==1){
	
	if(j==0 || j==2){
	  y1[i][j]=0.9-y_length;
	  y2[i][j]=0.9;
	}

	else if(j==1 || j==3){
	  y1[i][j]=0.5;
	  y2[i][j]=0.5+y_length;
	}
      }

      else if(i==2 || i==3){

	if(j==0 || j==2){
	  y1[i][j]=0.1;
	  y2[i][j]=0.1+y_length;
	}
	
	else if(j==1 || j==3){
	  y1[i][j]=0.5-y_length;
	  y2[i][j]=0.5;
	}
      }
    }
  }

  vector<Double_t>Xc;
  vector<Double_t>Yc;
  
  for(Int_t i=0; i<Tp; ++i){    
    Double_t olp=1;
    while(olp!=0){
      if(mi==0){
	break;
      }
      Int_t tmp=0;
      Double_t Npoints=1;
      if(secnumber==0){
	Xc=X1;
	Yc=Y1;
      }
      else if(secnumber==1){
	Xc=X2;
	Yc=Y2;     
      }
      else if(secnumber==2){
	Xc=X3;
	Yc=Y3;
      }
      else{
	Xc=X4;
	Yc=Y4;     
      }
      TLegend *leg_test = new TLegend(x1[secnumber][i],y1[secnumber][i],x2[secnumber][i],y2[secnumber][i]);
      for(Int_t i=0; i<Npoints; ++i){
	Double_t xpad=gPad->XtoPad(Xc.at(i));
	Double_t ypad=gPad->YtoPad(Yc.at(i));
	tmp=leg_test->IsInside(xpad,ypad);
	if(tmp!=0){
	  delete leg_test;
	  break;
	}
	else{
	  olp=tmp;
	}
      }            
    }

    TLegend* leg = new TLegend(x1[secnumber][i],y1[secnumber][i],x2[secnumber][i],y2[secnumber][i]);
    for(Int_t i=0; i<Nhists; ++i){      
      leg->AddEntry(hists_cp.at(i),hists_name.at(i),"l");
    }
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->Draw("SAME");
    gPad->RedrawAxis();
      
    break;
  }

  return plot;

};

///////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\ Drawing a simple th2d
TCanvas* SterileDraw::SimplePlot(TH2D* hist2d,TString xname,TString yname, TString name, Int_t colour_options){


  /*  
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  gStyle->SetOptStat(0);

  //here the actually interesting code starts
  const Double_t min = 0.9;
  const Double_t max = 1.1;

  const Int_t nLevels = 999;
  Double_t levels[nLevels];


  for(int i = 1; i < nLevels; i++) {
    levels[i] = min + (max - min) / (nLevels - 1) * (i);
  }
  levels[0] = 0.01;
  */

  Int_t locax;
  Int_t locay;
  Int_t locaz;
  cout << locax << ", " << locay << ", " << locaz << endl;
  hist2d->GetMaximumBin(locax,locay,locaz);
  cout << locax << ", " << locay << ", " << locaz << endl;
  Double_t xlocation=hist2d->GetXaxis()->GetBinCenter(locax);
  Double_t ylocation=hist2d->GetYaxis()->GetBinCenter(locay);

  TMarker* mark=new TMarker(xlocation,ylocation,5);
  mark->SetMarkerColor(kYellow);
  mark->SetMarkerSize(7);

  hist2d->SetTitle("");
  hist2d->SetXTitle(xname);
  hist2d->SetYTitle(yname);
  TCanvas *plot=new TCanvas(name,name,1600,800);
  gStyle->SetOptStat(0);
  gPad->SetTicks(1,1);
  gPad->Update();
  gStyle->SetOptStat(0);
  gPad->RedrawAxis();

  if(colour_options==0){
    const Int_t NRGBs = 5;
    const Int_t NCont = 104;
    Double_t gctstops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t gctred[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t gctgreen[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t gctblue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
  
  //Double_t minimum=hist->GetMinimum();
  }
  
  else if(colour_options==1){
    const Int_t NRGBs = 6;
    const Int_t NCont = 999;
    
    Double_t gctstops[NRGBs] = { 0.00, 0.1, 0.34, 0.61, 0.84, 1.00 };
    Double_t gctred[NRGBs]   = { 0.99, 0.0, 0.00, 0.87, 1.00, 0.51 };
    Double_t gctgreen[NRGBs] = { 0.00, 0.0, 0.81, 1.00, 0.20, 0.00 };
    Double_t gctblue[NRGBs]  = { 0.99, 0.0, 1.00, 0.12, 0.00, 0.00 };
    const Int_t nLevels = 999;
    Double_t levels[nLevels];
    
    TColor::CreateGradientColorTable(NRGBs, gctstops, gctred, gctgreen, gctblue, NCont);
    gStyle->SetNumberContours(NCont);
    
    Double_t max=hist2d->GetMaximum();
    Double_t min=hist2d->GetMinimum();
    
    for(int i = 1; i < nLevels; i++) {
      levels[i] = min + (max - min) / (nLevels - 1) * (i);
    }
    levels[0] = 0.01;
    hist2d->SetContour((sizeof(levels)/sizeof(Double_t)), levels);
      
      
  }

  hist2d->Draw("COLZ");
  mark->Draw("SAME");
  gPad->Update();

  return plot;

}

///////////////////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\ This is the Data/MC plot
TCanvas* SterileDraw::DoverMC(std::vector<TH1D*> hists, std::vector<TString> Legends, TString canvas_name, double xmaxrange, TString convert_text, Int_t PlotOpts){
  //Copy and load hists to the vector, so when you divide them it won't be overwrite.
  vector<TH1D*> UpperPlots;
  vector<TH1D*> LowerPlots;
  for(Int_t i=0; i<hists.size(); ++i){
    TH1D* CurHistUp = (TH1D*) hists.at(i)->Clone();
    CurHistUp->Sumw2();
    CurHistUp->SetDirectory(0);
    TH1D* FirstHistLow = (TH1D*) hists.at(0)->Clone();
    FirstHistLow->SetDirectory(0);
    if(i!=0){
      FirstHistLow->Sumw2();
      TH1D* CurHistLow=(TH1D*)hists.at(i)->Clone();
      CurHistLow->SetDirectory(0);
      FirstHistLow->Divide(CurHistLow);
      LowerPlots.push_back(FirstHistLow);
    }
    UpperPlots.push_back(CurHistUp);    

  }

  //This class convert abbr to it's proper form.
  SterileText* convert = new SterileText(1,true,true);
  //This class have stuff to check.
  SterileCheck* findcrest = new SterileCheck();  

  //Create canvas
  TCanvas* plot=new TCanvas(canvas_name,canvas_name,1600,1200);

  //Reset the name  
  TString name=UpperPlots.at(0)->GetName();
  name+="_Data/MC_Comparison";
  
  //Pad one upper plot
  TPad *pad1 = new TPad("pad1","MC and Data",0.0,0.2,1.0,1.0);
  pad1->SetBottomMargin(0.15);
  pad1->SetFillStyle(4000);
  pad1->SetFillColorAlpha(0,1.0);
  pad1->Draw();
  
  //Pad two lower plot
  TPad *pad2 = new TPad("pad2","MC over Data",0.0,0.0,1.0,0.4);
  pad2->SetTopMargin(0.2);
  pad2->SetBottomMargin(0.2);
  pad2->SetFillStyle(4000);
  pad2->SetFillColorAlpha(0,1.0);
  pad2->Draw();

  //Legend
  TLegend* leg= new TLegend(0.6,0.6,0.8,0.8);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  
  //For energy plots

  bool lowerplot = true;
  bool upperplot = true;

  //Range of x
  vector<double> xrange;      
  if(xmaxrange == 0){      
    cout << "Applying default plotting option" << endl;
    xrange.push_back(UpperPlots.at(0)->GetXaxis()->GetBinLowEdge(1));
    xrange.push_back(UpperPlots.at(0)->GetXaxis()->GetBinLowEdge((UpperPlots.at(0)->GetNbinsX()+1)));
  }  
  else{
    cout << "Applying selected plotting option" << endl;
    xrange.push_back(UpperPlots.at(0)->GetXaxis()->GetBinLowEdge(1));
    xrange.push_back(xmaxrange);    
  }    

  //Range of y
  Double_t ymax = findcrest->FindMaximum(UpperPlots);
  Double_t ymin = findcrest->FindMinimum(UpperPlots);
  //cout << ymin << "    " << ymax << endl;
  
  //Upper plot
  if(upperplot){

    //Into the pad
    pad1->cd();

    //Set the range and draw it
    for(Int_t i=0; i<UpperPlots.size(); ++i){      
      UpperPlots.at(i)->GetXaxis()->SetRangeUser(xrange.at(0),xrange.at(1));
      UpperPlots.at(i)->SetLineColor(i+1);
      
      leg->AddEntry(UpperPlots.at(i),Legends.at(i),"l");
      UpperPlots.at(i)->GetYaxis()->SetRangeUser(ymin,ymax);
      
      UpperPlots.at(i)->GetXaxis()->SetTickLength(0);
      UpperPlots.at(i)->GetXaxis()->SetLabelOffset(999);
      
      UpperPlots.at(i)->GetXaxis()->SetTitleSize(0);
      UpperPlots.at(i)->GetXaxis()->SetTitleOffset(999);
      
      UpperPlots.at(i)->GetYaxis()->SetTickLength(0);
      UpperPlots.at(i)->GetYaxis()->SetLabelOffset(999);

      if(i==0){
	if(PlotOpts == 0){
	  UpperPlots.at(i)->Draw("E"); 
	}
	else if(PlotOpts == 1){
	  UpperPlots.at(i)->Draw("HIST");
	}
      }
      else{
	UpperPlots.at(i)->Draw("HISTSAME");
      }
    }

    //Draw the legend
    leg->Draw("SAME");
    
    // Now redraw the 4 axis.
    TGaxis* xaxis1_top = new TGaxis(xrange.at(0),ymax,xrange.at(1),ymax,xrange.at(0),xrange.at(1),510,"+-");
    xaxis1_top->SetOption("S");
    xaxis1_top->SetLineColor(kBlack);
    xaxis1_top->SetLabelColor(kBlack);
    xaxis1_top->SetLabelOffset(0.03);
    xaxis1_top->SetTickSize(-0.04);
    xaxis1_top->CenterTitle();
    xaxis1_top->SetTitleFont(42);
    xaxis1_top->SetLabelFont(42);
    xaxis1_top->SetLabelSize(0.);    
    xaxis1_top->SetTitleSize(0.5);
    xaxis1_top->SetTitleOffset(0.7);
    xaxis1_top->SetDecimals(kTRUE);
    xaxis1_top->Draw("SAME");
    
    TGaxis* xaxis1_bottom = new TGaxis(xrange.at(0),ymin,xrange.at(1),ymin,xrange.at(0),xrange.at(1),510,"+L");
    xaxis1_bottom->SetOption("S");
    xaxis1_bottom->SetLineColor(kBlack);
    xaxis1_bottom->SetLabelColor(kBlack);
    xaxis1_bottom->SetTickSize(0.04);
    xaxis1_bottom->CenterTitle();
    xaxis1_bottom->SetTitleFont(42);
    xaxis1_bottom->SetLabelFont(42);
    xaxis1_bottom->SetLabelSize(0.);
    xaxis1_bottom->SetLabelOffset(999);
    xaxis1_bottom->SetDecimals(kTRUE);       
    xaxis1_bottom->SetTitleSize(0.);
    xaxis1_bottom->SetTitleOffset(999);
    xaxis1_bottom->Draw("SAME");
    
    TGaxis* yaxis1_left = new TGaxis(xrange.at(0),ymin,xrange.at(0),ymax,ymin,ymax,510,"+L");
    yaxis1_left->SetOption("S");
    yaxis1_left->SetLineColor(kBlack);
    yaxis1_left->SetLabelColor(kBlack);
    yaxis1_left->SetLabelOffset(0.02);
    yaxis1_left->SetTickSize(0.02);
    yaxis1_left->CenterTitle();
    yaxis1_left->SetTitleFont(42);
    yaxis1_left->SetLabelFont(42);
    yaxis1_left->SetLabelSize(0.04);
    yaxis1_left->SetLabelOffset(-0.0002);
    yaxis1_left->SetTitleSize(0.5);
    yaxis1_left->SetTitleOffset(0.7);
    yaxis1_left->SetDecimals(kTRUE);
    yaxis1_left->Draw("SAME");
    
    TGaxis* yaxis1_right = new TGaxis(xrange.at(1),ymin,xrange.at(1),ymax,ymin,ymax,510,"-");
    yaxis1_right->SetOption("S");
    yaxis1_right->SetLineColor(kBlack);
    yaxis1_right->SetLabelColor(kBlack);
    yaxis1_right->SetTickSize(-0.02);
    yaxis1_right->CenterTitle();
    yaxis1_right->SetTitleFont(42);
    yaxis1_right->SetLabelFont(42);
    yaxis1_right->SetLabelSize(0.);
    yaxis1_right->SetLabelOffset(-0.015);
    yaxis1_right->SetTitleSize(0.5);
    yaxis1_right->SetTitleOffset(0.7);
    yaxis1_right->SetDecimals(kTRUE);
    yaxis1_right->Draw("SAME");    
  }

  //bot plot
  if(lowerplot){
    
    pad2->cd();    
    for(Int_t i=0; i<LowerPlots.size(); ++i){
      
      LowerPlots.at(i)->GetXaxis()->SetRangeUser(xrange.at(0),xrange.at(1));
      LowerPlots.at(i)->SetLineColor(i+2);
      LowerPlots.at(i)->SetLineWidth(2);
      
      gStyle->SetGridStyle(0);
      
      LowerPlots.at(i)->GetXaxis()->SetTickLength(0);	
      LowerPlots.at(i)->GetXaxis()->SetLabelOffset(999);
      LowerPlots.at(i)->GetXaxis()->SetLabelSize(0);
      LowerPlots.at(i)->GetXaxis()->SetTitleOffset(999);
      LowerPlots.at(i)->GetXaxis()->SetTitleSize(0);
      
      LowerPlots.at(i)->GetYaxis()->SetRangeUser(0.5,1.5);
      LowerPlots.at(i)->GetYaxis()->SetTickLength(0);
      LowerPlots.at(i)->GetYaxis()->SetLabelOffset(999);
      LowerPlots.at(i)->GetYaxis()->SetLabelSize(0);
      LowerPlots.at(i)->GetYaxis()->SetTitleOffset(999);
      LowerPlots.at(i)->GetYaxis()->SetTitleSize(0);

      if(PlotOpts == 0){
	if(i==0){
	  LowerPlots.at(i)->Draw("E");
	}
	else{
	  LowerPlots.at(i)->Draw("ESAME");
	}
      }
      else if(PlotOpts == 1){
	if(i==0){
	  LowerPlots.at(i)->Draw("HIST");
	}
	else{
	  LowerPlots.at(i)->Draw("HISTSAME");
	}
      }
      
      TString entryname=Legends.at(0);
      entryname+="/";
      entryname+=Legends.at(i+1);
      
      leg->AddEntry(LowerPlots.at(i),entryname,"l");
      
    }

    //Draw the dash lines
    vector<TLine*> gridlines;
    for(Int_t i=6; i<15; i++){
      Double_t value=(Double_t)i/10.0;
      TLine* tmp = new TLine(xrange.at(0),value,xrange.at(1),value);
      //black dash line
      if(i==10 || i==6 || i==8 || i==12 || i==14){
	tmp->SetLineColor(kBlack);
	tmp->SetLineWidth(1);
	tmp->SetLineStyle(2);
	tmp->Draw("SAME");
	cout << "any hit?" << endl;
      }
      //grey dash line
      else{
	cout << i << " " << value << endl;
	tmp->SetLineColor(kBlack);
	tmp->SetLineWidth(1);
	tmp->SetLineStyle(3);
	tmp->Draw("SAME");
      }
      gridlines.push_back(tmp);	
    }

    //Redraw the four axes at the bot
    TGaxis* xaxis2_top = new TGaxis(xrange.at(0),1.5,xrange.at(1),1.5,xrange.at(0),xrange.at(1),510,"+-");
    xaxis2_top->SetOption("S");
    xaxis2_top->SetLineColor(kBlack);
    xaxis2_top->SetLabelColor(kBlack);
    xaxis2_top->SetTickSize(-0.06);
    xaxis2_top->CenterTitle();
    xaxis2_top->SetTitleFont(42);
    xaxis2_top->SetLabelFont(42);
    xaxis2_top->SetLabelSize(0.);    
    xaxis2_top->SetTitleSize(0.5);
    xaxis2_top->SetTitleOffset(0.5);
    xaxis2_top->SetDecimals(kTRUE);
    xaxis2_top->Draw("SAME");
    
    TGaxis* xaxis2_bottom = new TGaxis(xrange.at(0),0.5,xrange.at(1),0.5,xrange.at(0),xrange.at(1),510,"+L");
    xaxis2_bottom->SetOption("S");
    xaxis2_bottom->SetLineColor(kBlack);
    xaxis2_bottom->SetLabelColor(kBlack);
    xaxis2_bottom->SetTickSize(0.06);
    xaxis2_bottom->CenterTitle();
    xaxis2_bottom->SetTitleFont(42);
    xaxis2_bottom->SetLabelFont(42);
    xaxis2_bottom->SetLabelSize(0.08);
    
    xaxis2_bottom->SetDecimals(kTRUE);
    
    //xaxis Title reset name
    TString title_rearr = "";          
    if(convert_text == ""){
      TString xtitle = UpperPlots.at(0)->GetName();
      Ssiz_t size = xtitle.First("h");
      //xtitle.EStripType = TString::kTrailing;
      char c = '_';
      xtitle.Remove(size,size+2);
      Ssiz_t Remaining_one = xtitle.First("_");
      xtitle.Resize(Remaining_one);
      // Need to change SigQP to sigQP, so is sigQP_QP
      if(xtitle=="SigQP"){
	xtitle = "sigQP_QP";
      }    
      // Text convertion class, debug took me 3 days, I hate this
      TString title_rearr=convert->ConvertText(xtitle);
    }    
    else{
      title_rearr=convert_text;
    }
    
    xaxis2_bottom->SetTitle(title_rearr);
    xaxis2_bottom->SetTitleSize(0.08);
    xaxis2_bottom->SetTitleOffset(1.);
    xaxis2_bottom->Draw("SAME");
    
    TGaxis* yaxis2_left = new TGaxis(xrange.at(0),0.5,xrange.at(0),1.5,0.5,1.5,206,"+L");
    yaxis2_left->SetOption("S");
    yaxis2_left->SetLineColor(kBlack);
    yaxis2_left->SetLabelColor(kBlack);
    yaxis2_left->SetTickSize(0.02);
    yaxis2_left->CenterTitle();
    yaxis2_left->SetTitleFont(42);
    yaxis2_left->SetLabelFont(42);
    yaxis2_left->SetLabelSize(0.079);
    yaxis2_left->SetLabelOffset(0.02);
    yaxis2_left->SetTitleSize(0.5);
    yaxis2_left->SetTitleOffset(0.7);
    yaxis2_left->SetDecimals(kTRUE);
    yaxis2_left->Draw("SAME");
    
    TGaxis* yaxis2_right = new TGaxis(xrange.at(1),0.5,xrange.at(1),1.5,0.5,1.5,206,"-");
    yaxis2_right->SetOption("S");
    yaxis2_right->SetLineColor(kBlack);
    yaxis2_right->SetLabelColor(kBlack);
    yaxis2_right->SetTickSize(-0.02);
    yaxis2_right->CenterTitle();
    yaxis2_right->SetTitleFont(42);
    yaxis2_right->SetLabelFont(42);
    yaxis2_right->SetLabelSize(0.079);
    yaxis2_right->SetLabelOffset(-0.03);
    yaxis2_right->SetTitleSize(0.5);
    yaxis2_right->SetTitleOffset(0.7);
    yaxis2_right->SetDecimals(kTRUE);
    yaxis2_right->Draw("SAME");
      
  }  

  gStyle->SetOptTitle(kFALSE);
  gStyle->SetOptStat(0);
  gPad->RedrawAxis();
  
  return plot;
	
}
