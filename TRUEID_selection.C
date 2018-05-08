#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TString.h>
#include <iostream>
using namespace std;





void TRUEID_selection()
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
    
    // Bsst2 mass histogram med TrBs-cut
    TH1D *h_Bsst2_M_TrBs = new TH1D("Bsst2_M_TrBs","Bsst2_M_TrBs", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrBs->SetLineStyle(2);
    h_Bsst2_M_TrBs->SetLineWidth(2);
    h_Bsst2_M_TrBs->SetLineColor(kRed);
    
    // Bsst2 mass histogram med TrKm-cut
    TH1D *h_Bsst2_M_TrKm = new TH1D("Bsst2_M_TrKm","Bsst2_M_TrKm", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrKm->SetLineStyle(2);
    h_Bsst2_M_TrKm->SetLineWidth(2);
    h_Bsst2_M_TrKm->SetLineColor(3);
    
    // Bsst2 mass histogram med TrBp-cut
    TH1D *h_Bsst2_M_TrBp = new TH1D("Bsst2_M_TrBp","Bsst2_M_TrBp", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrBp->SetLineStyle(2);
    h_Bsst2_M_TrBp->SetLineWidth(2);
    h_Bsst2_M_TrBp->SetLineColor(4);
    
    // Bsst2 mass histogram med TrKp-cut
    TH1D *h_Bsst2_M_TrKp = new TH1D("Bsst2_M_TrKp","Bsst2_M_TrKp", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrKp->SetLineStyle(2);
    h_Bsst2_M_TrKp->SetLineWidth(2);
    h_Bsst2_M_TrKp->SetLineColor(5);
    
    // Bsst2 mass histogram med TrJp-cut
    TH1D *h_Bsst2_M_TrJp = new TH1D("Bsst2_M_TrJp","Bsst2_M_TrJp", bin_num , bin_min, bin_max);
    h_Bsst2_M_TrJp->SetLineStyle(2);
    h_Bsst2_M_TrJp->SetLineWidth(2);
    h_Bsst2_M_TrJp->SetLineColor(6);
    
    // Bsst2 mass histogram med Trmup-cut
    TH1D *h_Bsst2_M_Trmup = new TH1D("Bsst2_M_Trmup","Bsst2_M_Trmup", bin_num , bin_min, bin_max);
    h_Bsst2_M_Trmup->SetLineStyle(2);
    h_Bsst2_M_Trmup->SetLineWidth(2);
    h_Bsst2_M_Trmup->SetLineColor(7);
    
    // Bsst2 mass histogram med Trmum-cut
    TH1D *h_Bsst2_M_Trmum = new TH1D("Bsst2_M_Trmum","Bsst2_M_Trmum", bin_num , bin_min, bin_max);
    h_Bsst2_M_Trmum->SetLineStyle(2);
    h_Bsst2_M_Trmum->SetLineWidth(2);
    h_Bsst2_M_Trmum->SetLineColor(8);
    

    
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
        }
        
        // TRUEID == 321 ('K-')
        if ( sqrt(pow(Kminus_TRUEID,2)) == 321 ) {;
            h_Bsst2_M_TrKm->Fill(Bsst2_M);
        }
        
        // TRUEID == 521 ('B+')
        if ( sqrt(pow(Bplus_TRUEID,2)) == 521 ) {;
            h_Bsst2_M_TrBp->Fill(Bsst2_M);
        }
        
        // TRUEID == 321 ('K+')
        if ( sqrt(pow(Kplus_TRUEID,2)) == 321 ) {;
            h_Bsst2_M_TrKp->Fill(Bsst2_M);
        }
        
        // TRUEID == 443 ('Jpsi')
        if ( sqrt(pow(Jpsi_TRUEID,2)) == 443 ) {;
            h_Bsst2_M_TrJp->Fill(Bsst2_M);
        }
        
        // TRUEID == 13 ('mu-')
        if ( sqrt(pow(muminus_TRUEID,2)) == 13 ) {;
            h_Bsst2_M_Trmup->Fill(Bsst2_M);
        }
        
        // TRUEID == -13 ('mu+')
        if ( sqrt(pow(muplus_TRUEID,2)) == 13 ) {;
            h_Bsst2_M_Trmum->Fill(Bsst2_M);
        }
        // check for SS mu
        if ( muminus_TRUEID == muplus_TRUEID && sqrt(pow(muplus_TRUEID,2))== 13 ) {;
            cout << "samesign mumu in candidate = " << i << endl;
        }
        
        // check for SS K
        if ( Kminus_TRUEID == Kplus_TRUEID && sqrt(pow(Kplus_TRUEID,2))== 321 ) {;
            cout << "samesign KK in candidate = " << i << endl;
        }
        
    }



//------------------------------------------------------------------------------------------------
// DRAW HISTOGRAMS
    
    TCanvas *c0= new TCanvas ("c0","c0",800,800);
    c0->cd();
    c0->SetGrid();
    
    h_Bsst2_M->SetTitle("Mass distribution of Bsst2; M(Bsst2); counts");
    h_Bsst2_M->Draw("hist");
    h_Bsst2_M_TrBs->Draw("samehist");
    
    h_Bsst2_M_TrKm->Draw("samehist");
    h_Bsst2_M_TrBp->Draw("samehist");
    
    h_Bsst2_M_TrKp->Draw("samehist");
    h_Bsst2_M_TrJp->Draw("samehist");
    
    h_Bsst2_M_Trmum->Draw("samehist");
    h_Bsst2_M_Trmup->Draw("samehist");
    
    
    TLegend* leg1 = new TLegend(0.1,0.6,0.30,0.8);
    leg1->SetHeader("TRUEID Cut:");
    leg1->AddEntry(h_Bsst2_M,"without","f");
    leg1->AddEntry(h_Bsst2_M_TrBs,"Bsst2","f");
    leg1->AddEntry(h_Bsst2_M_TrKm,"Kminus","f");
    leg1->AddEntry(h_Bsst2_M_TrBp,"Bplus","f");
    leg1->AddEntry(h_Bsst2_M_TrKp,"Kplus","f");
    leg1->AddEntry(h_Bsst2_M_TrJp,"Jpsi","f");
    leg1->AddEntry(h_Bsst2_M_Trmup,"mu+","f");
    leg1->AddEntry(h_Bsst2_M_Trmum,"mu-","f");
    
    leg1->Draw();

    
    
    
    
//------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //h_PpD->GetYaxis()->SetRangeUser(0.0,0.4);
    
    
    
    
    
    /*
    
    TCanvas *c2= new TCanvas ("c2","c2",800,800);
    c2->cd();
    h_Piprob->SetTitle("DM with Piprob cut; DM; counts");
    h_Piprob->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c3= new TCanvas ("c3","c3",800,800);
    c3->cd();
    h_Muprob->SetTitle("DM with Muprob cut; DM; counts");
    h_Muprob->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c4= new TCanvas ("c4","c4",800,800);
    c4->cd();
    h_Kptot->SetTitle("DM with Kptot cut; DM; counts");
    h_Kptot->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c5= new TCanvas ("c5","c5",800,800);
    c5->cd();
    h_Piptot->SetTitle("DM with Piptot cut; DM; counts");
    h_Piptot->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c6= new TCanvas ("c6","c6",800,800);
    c6->cd();
    h_Kptrans->SetTitle("DM with Kptrans cut; DM; counts");
    h_Kptrans->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c7= new TCanvas ("c7","c7",800,800);
    c7->cd();
    h_Piptrans->SetTitle("DM with Piptrans cut; DM; counts");
    h_Piptrans->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c8= new TCanvas ("c8","c8",800,800);
    c8->cd();
    h_DV->SetTitle("DM with Dvertex cut; DM; counts");
    h_DV->Draw("hist");
    h_DM->Draw("SameHist");
    
    TCanvas *c9= new TCanvas ("c9","c9",800,800);
    c9->cd();
    h_DM_cut->SetTitle("DM with all cuts; DM; counts");
    h_DM_cut->Draw("hist");
    h_DM->Draw("SameHist");


        
        // All cuts at ones
        if ((pk1 >= 0.2)
            && (pk2 >= 0.2)
            && (ppi >= 0.2)
            && (pmu >= 0.2)
            // Momentum of K1, K2 and Pi
            && (sqrt( pow(pxk1,2) + pow(pzk1,2) + pow(pyk1,2))>=2000.0)
            && (sqrt( pow(pxk2,2) + pow(pzk2,2) + pow(pyk2,2))>=2000.0)
            && (sqrt( pow(pxpi,2) + pow(pzpi,2) + pow(pypi,2))>=2000.0)
            // Tranverse momentum of K1, K2 and Pi
            && (sqrt( pow(pxk1,2) + pow(pyk2,2))>=300.0)
            && (sqrt( pow(pxk2,2) + pow(pyk2,2))>=300.0)
            && (sqrt( pow(pxpi,2) + pow(pypi,2))>=300.0)
            // D Vertex Chi2 cut
            && (DV <= 6.0)
            )
            
        {;
            
            // DM histogram with cuts
            h_DM_cut->Fill(DM);
        } */
    
    
    
    /*
     
     // Integral after each cut
     
     // without cuts == all candidates
     double int_all = h_DM->Integral();
     // K prob cut
     double int_Kprob = h_Kprob->Integral();
     double int_Kprob_not = int_all - int_Kprob;
     // Pi prob cut
     double int_Piprob = h_Piprob->Integral();
     double int_Piprob_not = int_all-int_Piprob;
     // Mu prob cut
     double int_Muprob = h_Muprob->Integral();
     double int_Muprob_not = int_all-int_Muprob;
     // K Ptot cut
     double int_Kptot = h_Kptot->Integral();
     double int_Kptot_not = int_all-int_Kptot;
     // Pi Ptot cut
     double int_Piptot = h_Piptot->Integral();
     double int_Piptot_not = int_all-int_Piptot;
     // K Ptrans cut
     double int_Kptrans = h_Kptrans->Integral();
     double int_Kptrans_not = int_all-int_Kptrans;
     // Pi Ptrans cut
     double int_Piptrans = h_Piptrans->Integral();
     double int_Piptrans_not = int_all-int_Piptrans;
     // D Vertex cut
     double int_DV = h_DV->Integral();
     double int_DV_not = int_all-int_DV;
     // all cuts
     double int_all_cuts = h_DM_cut->Integral();
     double int_all_cuts_not = int_all-int_all_cuts;
     
     // calculating efficiencies
     
     double eff_Kprob = int_Kprob/int_all;
     double eff_Piprob = int_Piprob/int_all;
     double eff_Muprob = int_Muprob/int_all;
     double eff_Kptot = int_Kptot/int_all;
     double eff_Piptot = int_Piptot/int_all;
     double eff_Kptrans = int_Kptrans/int_all;
     double eff_Piptrans = int_Piptrans/int_all;
     double eff_Dv = int_DV/int_all;
     double eff_all = int_all_cuts/int_all;
     
     
     
     
     // printing efficiencies and errors
     
     cout << "Signal efficiencies for each cut: eff = Ncut/Ntot" << endl;
     cout << " I_all = " << int_all << endl;
     cout << " eff for K_prob cut = " << eff_Kprob << " error = " << error_on_eff(int_Kprob,int_Kprob_not) << endl;
     cout << " eff for Pi_prob cut = " << eff_Piprob << " error = " << error_on_eff(int_Piprob,int_Piprob_not)<< endl;
     cout << " eff for Mu_prob cut = " << eff_Muprob << " error = " << error_on_eff(int_Muprob,int_Muprob_not)<< endl;
     cout << " eff for K_ptot cut = " << eff_Kptot << " error = " << error_on_eff(int_Kptot,int_Kptot_not)<< endl;
     cout << " eff for Pi_ptot cut = " << eff_Piptot << " error = " << error_on_eff(int_Piptot,int_Piptot_not)<< endl;
     cout << " eff for K_ptrans cut = " << eff_Kptrans << " error = " << error_on_eff(int_Kptrans,int_Kptrans_not)<< endl;
     cout << " eff for Pi_ptrans cut = " << eff_Piptrans << " error = " << error_on_eff(int_Piptrans,int_Piptrans_not)<< endl;
     cout << " eff for D-vertex cut = " << eff_Dv << " error = " << error_on_eff(int_DV,int_DV_not)<< endl;
     cout << " eff for all cuts = " << eff_all << " error = " << error_on_eff(int_all_cuts,int_all_cuts_not)<< endl;
     
     */
    
    
    
    return ;
}

