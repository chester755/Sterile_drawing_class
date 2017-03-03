#ifndef __SterileDraw__
#define __SterileDraw__
#endif

#include <iostream>
#include <string>
#include "TString.h"
#include "TH2.h"
#include "TH2D.h"
#include "TMath.h"
#include "TObject.h"
#include "TCanvas.h"
#include "TSystem.h"

using namespace std;

class SterileDraw: public TObject{
 protected:
  

 private:
  
  Double_t ZMinValue=0;
  Double_t ZMaxValue=0;
  
 public:
  SterileDraw(){};
  SterileDraw(TString drawing_option, TString canvas_name, TH2D* hist2d);
  
  //SterileCheck* check;
  TCanvas* FoverNDraw(TString canvas_name, Double_t x_maximum_range, TH1D* FoN1d);
  TCanvas* MatrixDraw(TString canvas_name, TH2D* maxtrix_hist2d, Bool_t SetZRangemanually);
  TCanvas* FANMatrixDraw(TString canvas_name, TH2D* maxtrix_hist2d, Bool_t SetZRangemanually);

  TCanvas* ErrorBandPlot(TString canvas_name, TH1D* hist1d_positive, TH1D* hist1d_negative);
  TCanvas* ErrorBandPlot(TString canvas_name, TH1D* hist1d_positive, TH1D* hist1d_negative, Double_t XRange);
  TCanvas* ErrorBandPlotComp(TString canvas_name, Double_t shift_value, TH1D* hist1d_postive, TH1D* hist1d_negative);
  TCanvas* GSPlot(std::vector<TH1D*> hist1d_all, TString canvas_name, Int_t draw_options = 0, Int_t style_options = 0);
  TCanvas* SimplePlot(TH2D* hist2d,TString xname,TString yname, TString canvas_name, Int_t color_options=0);
  TCanvas* DoverMC(std::vector<TH1D*> hists, std::vector<TString> Legends, TString canvas_name, double xmaxrange=0, TString convert_text = "", Int_t PlotOpts=0);
  void SetMatrixValue(Double_t minimum_value, Double_t maximum_value);
  ~SterileDraw(){};
  
  ClassDef(SterileDraw,4);
};
