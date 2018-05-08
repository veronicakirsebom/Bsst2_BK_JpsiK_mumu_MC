#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TString.h>
#include <iostream>
using namespace std;



Double_t Mass_4vec(Double_t E, Double_t PX, Double_t PY, Double_t PZ )
{

    
    Double_t M = sqrt(pow(E,2)-pow(PX,2)-pow(PY,2)-pow(PZ,2));
    
    return M;
}



void massBsst2_distr_TRUE_vs_VIS()
{

    //##### MC data
    TString file_name = "Bs2stBPlusKMinus.root";
    TString subfile_name = "Bs2stBPlusKMinusTuple/DecayTree"; //
    
    // print data type MC/Real DATA
    if (file_name == "Bs2stBPlusKMinus.root"){;
        cout << "using MC DATA" <<endl;
    }

        

//------------------------------------------------------------------------------------------------
// OPEN DATA FILE AND TREE
    
    // Datafile
	TFile *file = TFile::Open(file_name);
	if (!file) {
		std::cout << "Cannot open :(" << file_name << std::endl;
    }
    if (file) {
        cout << "file is open :D " << endl;
    }
    

    // Tree
	TTree *tree;
	tree = (TTree*) file->Get(subfile_name);
	if (!tree) {
		std::cout << "Cannot find tree :(" << std::endl;
    }
    if (tree) {
        cout << "tree is found :D " << endl;
    }


    

//------------------------------------------------------------------------------------------------
// SET BRANCH ADDRESS
    
    
    // Bsst2_TRUEID
    Int_t Bsst2_TRUEID(0.);
    tree->SetBranchAddress("Bsst2_TRUEID", &Bsst2_TRUEID);
    
    // Kminus_TRUEID
    Int_t Kminus_TRUEID(0.);
    tree->SetBranchAddress("Kminus_TRUEID", &Kminus_TRUEID);
    
    // Bplus_TRUEID
    Int_t Bplus_TRUEID(0.);
    tree->SetBranchAddress("Bplus_TRUEID", &Bplus_TRUEID);

    // Kplus_TRUEID
    Int_t Kplus_TRUEID(0.);
    tree->SetBranchAddress("Kplus_TRUEID", &Kplus_TRUEID);
    
    // Jpsi_TRUEID
    Int_t Jpsi_TRUEID(0.);
    tree->SetBranchAddress("Jpsi_TRUEID", &Jpsi_TRUEID);
    
    // muplus_TRUEID
    Int_t muplus_TRUEID(0.);
    tree->SetBranchAddress("muplus_TRUEID", &muplus_TRUEID);
    
    // muminus_TRUEID
    Int_t muminus_TRUEID(0.);
    tree->SetBranchAddress("muminus_TRUEID", &muminus_TRUEID);

//---------
    
    // Bsst2_M
    Double_t Bsst2_M(0.);
    tree->SetBranchAddress("Bsst2_M", &Bsst2_M);

//---------

    // muplus TRUE E
    Double_t muplus_TRUEP_E(0.);
    tree->SetBranchAddress("muplus_TRUEP_E", &muplus_TRUEP_E);
    
    // muplus TRUE PX
    Double_t muplus_TRUEP_X(0.);
    tree->SetBranchAddress("muplus_TRUEP_X", &muplus_TRUEP_X);
    
    // muplus TRUE PY
    Double_t muplus_TRUEP_Y(0.);
    tree->SetBranchAddress("muplus_TRUEP_Y", &muplus_TRUEP_Y);
    
    // muplus TRUE PZ
    Double_t muplus_TRUEP_Z(0.);
    tree->SetBranchAddress("muplus_TRUEP_Z", &muplus_TRUEP_Z);

//---------
    
    // muminus TRUE E
    Double_t muminus_TRUEP_E(0.);
    tree->SetBranchAddress("muminus_TRUEP_E", &muminus_TRUEP_E);
    
    // muminus TRUE PX
    Double_t muminus_TRUEP_X(0.);
    tree->SetBranchAddress("muminus_TRUEP_X", &muminus_TRUEP_X);
    
    // muminus TRUE PY
    Double_t muminus_TRUEP_Y(0.);
    tree->SetBranchAddress("muminus_TRUEP_Y", &muminus_TRUEP_Y);
    
    // muminus TRUE PZ
    Double_t muminus_TRUEP_Z(0.);
    tree->SetBranchAddress("muminus_TRUEP_Z", &muminus_TRUEP_Z);
 
    
//---------
    
    // Kplus TRUE E
    Double_t Kplus_TRUEP_E(0.);
    tree->SetBranchAddress("Kplus_TRUEP_E", &Kplus_TRUEP_E);
    
    // Kplus TRUE PX
    Double_t Kplus_TRUEP_X(0.);
    tree->SetBranchAddress("Kplus_TRUEP_X", &Kplus_TRUEP_X);
    
    // Kplus TRUE PY
    Double_t Kplus_TRUEP_Y(0.);
    tree->SetBranchAddress("Kplus_TRUEP_Y", &Kplus_TRUEP_Y);
    
    // Kplus TRUE PZ
    Double_t Kplus_TRUEP_Z(0.);
    tree->SetBranchAddress("Kplus_TRUEP_Z", &Kplus_TRUEP_Z);
    
//---------
    
    // Kminus TRUE E
    Double_t Kminus_TRUEP_E(0.);
    tree->SetBranchAddress("Kminus_TRUEP_E", &Kminus_TRUEP_E);
    
    // Kminus TRUE PX
    Double_t Kminus_TRUEP_X(0.);
    tree->SetBranchAddress("Kminus_TRUEP_X", &Kminus_TRUEP_X);
    
    // Kminus TRUE PY
    Double_t Kminus_TRUEP_Y(0.);
    tree->SetBranchAddress("Kminus_TRUEP_Y", &Kminus_TRUEP_Y);
    
    // Kminus TRUE PZ
    Double_t Kminus_TRUEP_Z(0.);
    tree->SetBranchAddress("Kminus_TRUEP_Z", &Kminus_TRUEP_Z);
    
//---------
//---------
    
    // muplus E
    Double_t muplus_PE(0.);
    tree->SetBranchAddress("muplus_PE", &muplus_PE);
    
    // muplus PX
    Double_t muplus_PX(0.);
    tree->SetBranchAddress("muplus_PX", &muplus_PX);
    
    // muplus PY
    Double_t muplus_PY(0.);
    tree->SetBranchAddress("muplus_PY", &muplus_PY);
    
    // muplus PZ
    Double_t muplus_PZ(0.);
    tree->SetBranchAddress("muplus_PZ", &muplus_PZ);
    
    //---------
    
    // muminus E
    Double_t muminus_PE(0.);
    tree->SetBranchAddress("muminus_PE", &muminus_PE);
    
    // muminus PX
    Double_t muminus_PX(0.);
    tree->SetBranchAddress("muminus_PX", &muminus_PX);
    
    // muminus PY
    Double_t muminus_PY(0.);
    tree->SetBranchAddress("muminus_PY", &muminus_PY);
    
    // muminus PZ
    Double_t muminus_PZ(0.);
    tree->SetBranchAddress("muminus_PZ", &muminus_PZ);
    
    
    //---------
    
    // Kplus E
    Double_t Kplus_PE(0.);
    tree->SetBranchAddress("Kplus_PE", &Kplus_PE);
    
    // Kplus PX
    Double_t Kplus_PX(0.);
    tree->SetBranchAddress("Kplus_PX", &Kplus_PX);
    
    // Kplus PY
    Double_t Kplus_PY(0.);
    tree->SetBranchAddress("Kplus_PY", &Kplus_PY);
    
    // Kplus PZ
    Double_t Kplus_PZ(0.);
    tree->SetBranchAddress("Kplus_PZ", &Kplus_PZ);
    
    //---------
    
    // Kminus E
    Double_t Kminus_PE(0.);
    tree->SetBranchAddress("Kminus_PE", &Kminus_PE);
    
    // Kminus PX
    Double_t Kminus_PX(0.);
    tree->SetBranchAddress("Kminus_PX", &Kminus_PX);
    
    // Kminus PY
    Double_t Kminus_PY(0.);
    tree->SetBranchAddress("Kminus_PY", &Kminus_PY);
    
    // Kminus PZ
    Double_t Kminus_PZ(0.);
    tree->SetBranchAddress("Kminus_PZ", &Kminus_PZ);
    
    
    
    
    //------------------------------------------------------------------------------------------------
// DEFINE HISTOGRAMS
    
    Long64_t bin_min=5000;
    Long64_t bin_max=7500;
    Long64_t bin_num=100;
    
    // Bsst2 mass histogram
    TH1D *h_Bsst2_M = new TH1D("h_Bsst2_M","h_Bsst2_M", bin_num , bin_min , bin_max);
    h_Bsst2_M->SetLineStyle(1);
    h_Bsst2_M->SetLineWidth(2);
    h_Bsst2_M->SetLineColor(kBlack);
    
    // Bsst2 mass histogram calculated TRUE
    TH1D *h_Bsst2_M_calcTr = new TH1D("h_Bsst2_M_calcTr","h_Bsst2_M_calcTr", bin_num , bin_min , bin_max);
    h_Bsst2_M_calcTr->SetLineStyle(1);
    h_Bsst2_M_calcTr->SetLineWidth(2);
    h_Bsst2_M_calcTr->SetLineColor(kGreen);
    
    // Bsst2 mass histogram calculated VIS
    TH1D *h_Bsst2_M_calc = new TH1D("h_Bsst2_M_calc","h_Bsst2_M_calc", bin_num , bin_min , bin_max);
    h_Bsst2_M_calc->SetLineStyle(1);
    h_Bsst2_M_calc->SetLineWidth(2);
    h_Bsst2_M_calc->SetLineColor(kBlue);
    
    // Bsst2 mass histogram med TrBs-cut
    TH1D *h_Bsst2_M_TrBs = new TH1D("Bsst2_M_TrBs","Bsst2_M_TrBs", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrBs->SetLineStyle(2);
    h_Bsst2_M_TrBs->SetLineWidth(2);
    h_Bsst2_M_TrBs->SetLineColor(kRed);
    

    
//------------------------------------------------------------------------------------------------
// LOOPING OVER TREE AND APPLYING INDIVIDUAL CUTS
    
    Long64_t nentries = tree->GetEntriesFast();
    cout << "total number of entries in tree = " << nentries << endl;
    for (Long64_t i=0; i<nentries; i++) {
        
        // DM histogram without cuts
        tree->GetEntry(i);
        h_Bsst2_M->Fill(Bsst2_M);
        
        
        // abs(TRUEID) == 535 ('Bsst2')
        if ( sqrt(pow(Bsst2_TRUEID,2)) == 535 ) {;
            
            h_Bsst2_M_TrBs->Fill(Bsst2_M);
            
            // calculating the true invariant mass from mu+mu-K-K+
            Double_t mass_calcTr = Mass_4vec(muplus_TRUEP_E+muminus_TRUEP_E+Kplus_TRUEP_E+Kminus_TRUEP_E,muplus_TRUEP_X+muminus_TRUEP_X+Kplus_TRUEP_X+Kminus_TRUEP_X , muplus_TRUEP_Y+muminus_TRUEP_Y+Kplus_TRUEP_Y+Kminus_TRUEP_Y , muplus_TRUEP_Z+muminus_TRUEP_Z+Kplus_TRUEP_Z+Kminus_TRUEP_Z);
            //cout << "mass_calcTr = " << mass_calcTr << endl;
            
            Double_t mass_calc = Mass_4vec(muplus_PE+muminus_PE+Kplus_PE+Kminus_PE,muplus_PX+muminus_PX+Kplus_PX+Kminus_PX , muplus_PY+muminus_PY+Kplus_PY+Kminus_PY , muplus_PZ+muminus_PZ+Kplus_PZ+Kminus_PZ);
            //cout << "mass_calcTr = " << mass_calc << endl;
            
            h_Bsst2_M_calc->Fill(mass_calc);
            h_Bsst2_M_calcTr->Fill(mass_calcTr);
        }
        
    }



//------------------------------------------------------------------------------------------------
// DRAW HISTOGRAMS
    
    
    TCanvas *c1= new TCanvas ("c1","c1",800,800);
    c1->cd();
    c1->SetGrid();
    
    h_Bsst2_M->SetTitle("Mass distribution of Bsst2; M(Bsst2); counts");
    h_Bsst2_M->Draw("hist");
    h_Bsst2_M_calcTr->Draw("samehist");
    h_Bsst2_M_calc->Draw("samehist");
    h_Bsst2_M_TrBs->Draw("samehist");
    
    TLegend* leg2 = new TLegend(0.1,0.6,0.30,0.8);
    leg2->SetHeader("Bsst2 mass:");
    leg2->AddEntry(h_Bsst2_M,"without cuts","f");
    leg2->AddEntry(h_Bsst2_M_calcTr,"Calculated from TRUE E&P for K+K-mu+mu-","f");
    leg2->AddEntry(h_Bsst2_M_calc,"Calculated from VIS E&P for K+K-mu+mu-","f");
    leg2->AddEntry(h_Bsst2_M_TrBs,"TRUE-ID(Bsst2)","f");
    
    leg2->Draw();
    
    
    
    
    
//------------------------------------------------------------------------------------------------
    

    
    
    return ;
}

