#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TString.h>
#include <iostream>
#include <TVector3.h>
using namespace std;


// Bsst2 -> B+K- -> K+mu+(mu-) K-

// Finding the missing mass og mu-

void missingMass()
{
    //------------------------------------
    // CONSTANTS (PDG: 2/5-2018)
    
    MBsst2 = 5839.85; // ±0.17 MeV;
    MB  = 5279.32;  // ±0.14 MeV
    MK  = 493.677; // ±0.016 MeV
    Mmu = 105.6583745; // ± 0.0000024 MeV
    delta2 = pow(MBsst2,2)-pow(MB,2)-pow(MK,2);
    
    cout << " delta2 = " <<  delta2 << endl;
    

    
    //------------------------------------
    // MC DATA
    
     TString file_name = "Bs2stBPlusKMinus.root";
     TString subfile_name = "Bs2stBPlusKMinusTuple/DecayTree"; //
     // File
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
     
    //------------------------------------
    // DECLARE TREE-VARIABLES
    
    // Bsst2_TRUEID
    Int_t Bsst2_TRUEID(0.);
    tree->SetBranchAddress("Bsst2_TRUEID", &Bsst2_TRUEID);
    
    
    //--------- PRIMARY-VERTEX
    // PVX
    Double_t PV_X(0.);
    tree->SetBranchAddress("Bplus_OWNPV_X", &PV_X);
    
    // PVY
    Double_t PV_Y(0.);
    tree->SetBranchAddress("Bplus_OWNPV_Y", &PV_Y);
    
    // PVZ
    Double_t PV_Z(0.);
    tree->SetBranchAddress("Bplus_OWNPV_Z", &PV_Z);
    
    
    
    //--------- SECONDARY-VERTEX
    // SVX
    Double_t SV_X(0.);
    tree->SetBranchAddress("Bplus_ENDVERTEX_X", &SV_X);
    
    // SVY
    Double_t SV_Y(0.);
    tree->SetBranchAddress("Bplus_ENDVERTEX_Y", &SV_Y);
    
    // SVZ
    Double_t SV_Z(0.);
    tree->SetBranchAddress("Bplus_ENDVERTEX_Z", &SV_Z);
    
    
    //--------- 4-momentum mu+
    // muplus E
    Double_t Emu1(0.);
    tree->SetBranchAddress("muplus_PE", &Emu1 );
    
    // muplus PX
    Double_t px_mu1(0.);
    tree->SetBranchAddress("muplus_PX", &px_mu1);
    
    // muplus PY
    Double_t py_mu1(0.);
    tree->SetBranchAddress("muplus_PY", &py_mu1);
    
    // muplus PZ
    Double_t pz_mu1(0.);
    tree->SetBranchAddress("muplus_PZ", &pz_mu1);
    
 
    
    //--------- 4-momentum mu-
    
    /*
    // muminus E
    Double_t Emu2(0.);
    tree->SetBranchAddress("muminus_PE", &Emu2);
    
    // muminus PX
    Double_t px_mu2(0.);
    tree->SetBranchAddress("muminus_PX", &px_mu2);
    
    // muminus PY
    Double_t py_mu2(0.);
    tree->SetBranchAddress("muminus_PY", &py_mu2);
    
    // muminus PZ
    Double_t pz_mu2(0.);
    tree->SetBranchAddress("muminus_PZ", &pz_mu2);
    */
    
    //
    Double_t muplus_M(0.);
    tree->SetBranchAddress("muplus_M", &muplus_M);
    
    //--------- 4-momentum K-
    // Kminus E
    Double_t EK1(0.);
    tree->SetBranchAddress("Kminus_PE", &EK1);
    
    // Kminus PX
    Double_t px_K1(0.);
    tree->SetBranchAddress("Kminus_PX", &px_K1);
    
    // Kminus PY
    Double_t py_K1(0.);
    tree->SetBranchAddress("Kminus_PY", &py_K1);
    
    // Kminus PZ
    Double_t pz_K1(0.);
    tree->SetBranchAddress("Kminus_PZ", &pz_K1);
    
    
    
    //--------- 4-momentum K+
    // Kplus E
    Double_t EK2(0.);
    tree->SetBranchAddress("Kplus_PE", &EK2);
    
    // Kplus PX
    Double_t px_K2(0.);
    tree->SetBranchAddress("Kplus_PX", &px_K2);
    
    // Kplus PY
    Double_t py_K2(0.);
    tree->SetBranchAddress("Kplus_PY", &py_K2);
    
    // Kplus PZ
    Double_t pz_K2(0.);
    tree->SetBranchAddress("Kplus_PZ", &pz_K2);
    
    
    //--------- B+ energy
    // Kplus E
    Double_t Bplus_PE(0.);
    tree->SetBranchAddress("Bplus_PE", &Bplus_PE);
    
    
    //------------------------------------
    // DEFINE HISTOGRAMS
    
    
    
    //------B+ energy histograms
    Long64_t bin_minE = 0;
    Long64_t bin_maxE = 7.6e5;
    Long64_t bin_numE = 100;

    // B+ energy directly from MC
    TH1D *h_EB_MC = new TH1D("h_EB_MC","h_EB_MC", bin_numE , bin_minE , bin_maxE);
    h_EB_MC->SetLineStyle(1);
    h_EB_MC->SetLineWidth(2);
    h_EB_MC->SetLineColor(kBlack);
    
    // B+ energy EB+ solution
    TH1D *h_EB_plus = new TH1D("h_EB_plus","h_EBplus", bin_numE , bin_minE , bin_maxE);
    h_EB_plus->SetLineStyle(1);
    h_EB_plus->SetLineWidth(2);
    h_EB_plus->SetLineColor(kRed);
    
    // B+ energy for EB- solution
    TH1D *h_EB_minus = new TH1D("h_EB_minus","h_EB_minus", bin_numE , bin_minE , bin_maxE);
    h_EB_minus->SetLineStyle(1);
    h_EB_minus->SetLineWidth(2);
    h_EB_minus->SetLineColor(kBlue);
    
    //-----missing mass histograms
    Long64_t bin_min = -2e+7;
    Long64_t bin_max = 1e+7;
    Long64_t bin_num = 150;
    
    // missing mass for detected mu-
    TH1D *h_MM2_detected = new TH1D("h_MM2_detected","h_MM2_detected", bin_num , bin_min , bin_max);
    h_MM2_detected->SetLineStyle(1);
    h_MM2_detected->SetLineWidth(2);
    h_MM2_detected->SetLineColor(kBlack);
    
    // missing mass for EB+ solution
    TH1D *h_MM2_plus = new TH1D("h_MM2_plus","h_MM2_plus", bin_num , bin_min , bin_max);
    h_MM2_plus->SetLineStyle(1);
    h_MM2_plus->SetLineWidth(2);
    h_MM2_plus->SetLineColor(kRed);
    
    // missing mass for EB- solution
    TH1D *h_MM2_minus = new TH1D("h_MM2_minus","h_MM2_minus", bin_num , bin_min , bin_max);
    h_MM2_minus->SetLineStyle(1);
    h_MM2_minus->SetLineWidth(2);
    h_MM2_minus->SetLineColor(kBlue);
    
    
    

    //------------------------------------
    // LOOPING OVER TREE AND APPLYING INDIVIDUAL CUTS
    
    Int_t N_Bsst2 = 0;
    Int_t N_imag = 0;
    Int_t N_EBplus = 0;
    Int_t N_EBminus = 0;
    Int_t N_no_solution = 0;
    Int_t N_EB_negative_value = 0;
    
    Long64_t nentries = tree->GetEntriesFast();
    cout << "total number of entries in tree = " << nentries << endl;
    for (Long64_t i=0; i<nentries; i++) {
        
        tree->GetEntry(i);
        
        if (535 == abs(Bsst2_TRUEID)) {
            
            // counting number of (real) Bsst2
            N_Bsst2++;
            
            // MM2 for detected mu-
            h_MM2_detected->Fill(muplus_M*muplus_M);
            h_EB_MC->Fill(Bplus_PE);
            
            
        
            // 3-momentum K1 (K-)
            TVector3 pK1(px_K1,py_K1,pz_K1);
        
            // flight-direction B+
            TVector3 dB(SV_X-PV_X, SV_Y-PV_Y, SV_Z-PV_Z);
            // unit vector
            TVector3 dB_unit = dB.Unit();
        
            // dot product BK
            Double_t dot_BK = pK1.Dot(dB);
        
            // length of vectors
            Double_t len_dB = sqrt(dB.X()*dB.X() + dB.Y()*dB.Y() + dB.Z()*dB.Z()) ;
            Double_t len_pK1 = sqrt(pK1.X()*pK1.X() + pK1.Y()*pK1.Y() + pK1.Z()*pK1.Z()) ;
        
            // cosine of angle between B and K
            Double_t cos_BKangle = dot_BK / (len_dB * len_pK1);
        
            // Energy and mass of visible decay products K2 and mu1 (K+ and mu+)
            Double_t Evis = EK2 + Emu1 ;
            Double_t Mvis = MK + Mmu ;
        
            // 4-momentum of visible decay products
            TLorentzVector pvis(px_K2+px_mu1,py_K2+py_mu1,pz_K2+pz_mu1,Evis);
        
            //rotate with respect to B+ flight direction frame
            pvis.RotateUz(dB_unit); //
        
            // Two solutions to B+ energy using m(BK) == m(Bsst2)
            Double_t a = EK1*EK1 - len_pK1*len_pK1 * cos_BKangle*cos_BKangle;
            Double_t b = -EK1*delta2;
            Double_t c = MB*MB * len_pK1*len_pK1 * cos_BKangle*cos_BKangle + 1.0/4.0 * delta2*delta2;
            Double_t d = b*b-4*a*c ;
        
            Double_t EB_plus = (-b+sqrt(d))/(2*a);
            Double_t EB_minus = (-b-sqrt(d))/(2*a);
            
            if (d<0){
                N_imag++;
                cout << "d < 0 " << endl;
                cout << "EB_plus = " << EB_plus << endl;
                cout << "EB_minus = " << EB_minus << endl;
            }
            
            if ((EB_plus<0) || (EB_minus<0)){
                N_EB_negative_value++;
                cout << "(EB_plus<0)/EB_minus<0)" << endl;
            }
        
            if ((EB_plus > 0) && (EB_plus>Evis)){
            
                N_EBplus++;
                
                TLorentzVector pB_plus(0,0,sqrt(EB_plus*EB_plus-MB*MB),EB_plus);
                Double_t MM2_plus = (pB_plus.E()-pvis.E())*(pB_plus.E()-pvis.E()) - (pB_plus.Px()-pvis.Px())*(pB_plus.Px()-pvis.Px()) - (pB_plus.Py()-pvis.Py())*(pB_plus.Py()-pvis.Py()) - (pB_plus.Pz()-pvis.Pz())*(pB_plus.Pz()-pvis.Pz());
            
                //Double_t MM2_plus = (pB_plus-pvis)*(pB_plus-pvis);
                cout << "EB_plus = " << EB_minus << endl;
                cout << "MM2_plus = " << MM2_plus << endl;
                h_MM2_plus->Fill(MM2_plus);
                h_EB_plus->Fill(EB_plus);
            }
        
            if ((EB_minus > 0) && (EB_minus>Evis)){
                
                N_EBminus++;
            
                TLorentzVector pB_minus(0,0,sqrt(EB_minus*EB_minus-MB*MB),EB_plus);
                Double_t MM2_minus = (pB_minus.E()-pvis.E())*(pB_minus.E()-pvis.E()) - (pB_minus.Px()-pvis.Px())*(pB_minus.Px()-pvis.Px()) - (pB_minus.Py()-pvis.Py())*(pB_minus.Py()-pvis.Py()) - (pB_minus.Pz()-pvis.Pz())*(pB_minus.Pz()-pvis.Pz());
            
                //Double_t MM2_minus = (pB_minus-pvis)*(pB_minus-pvis);
                cout << "EB_minus = " << EB_minus << endl;
                cout << "MM2_minus = " << MM2_minus << endl;
                h_MM2_minus->Fill(MM2_minus);
                h_EB_minus->Fill(EB_minus);
            }
        
            else {
                N_no_solution++;
                cout << "No solution" << endl;
            }
        }
    }
    
    cout << "N_Bsst2 = " << N_Bsst2 << endl;
    cout << "N_imag = " << N_imag << endl;
    cout << "N_EBplus = " << N_EBplus << endl;
    cout << "N_EBminus = " << N_EBminus << endl;
    cout << "N_no_solution = " << N_no_solution << endl;
    


//------------------------------------------------------------------------------------------------
// DRAW HISTOGRAMS
    
    // Missing mu- mass
    TCanvas *c1= new TCanvas ("c1","c1",800,800);
    c1->cd();
    c1->SetGrid();
    
    h_MM2_detected->SetTitle("Missing mass of mu-; MM^2 MeV^2 ; counts");
    h_MM2_detected->Draw("hist");
    h_MM2_plus->Draw("samehist");
    h_MM2_minus->Draw("samehist");
    
    TLegend* leg2 = new TLegend(0.1,0.6,0.30,0.8);
    leg2->SetHeader("MM^2 for:");
    leg2->AddEntry(h_MM2_detected,"Detected mu-","f");
    leg2->AddEntry(h_MM2_plus,"EB_plus solution","f");
    leg2->AddEntry(h_MM2_minus,"EB_minus solution","f");
    leg2->Draw();
    
    // B+ energy
    TCanvas *c2= new TCanvas ("c2","c2",800,800);
    c2->cd();
    c2->SetGrid();
    
    h_EB_MC->SetTitle("B+ energy; E(B+) MeV ; counts");
    h_EB_MC->Draw("hist");
    h_EB_plus->Draw("samehist");
    h_EB_minus->Draw("samehist");
    
    TLegend* leg3 = new TLegend(0.1,0.6,0.30,0.8);
    leg3->SetHeader("E(B+) for:");
    leg3->AddEntry(h_MM2_detected,"MC/Detected mu-","f");
    leg3->AddEntry(h_MM2_plus,"EB_plus solution","f");
    leg3->AddEntry(h_MM2_minus,"EB_minus solution","f");
    leg3->Draw();
    
    
    /*
    TCanvas *c1= new TCanvas ("c1","c1",800,800);
    c1->cd();
    c1->SetGrid();
    
    h_MM2_plus->SetTitle("Missing mass of mu-; MM^2 MeV^2 ; counts");
    h_MM2_plus->Draw("hist");
    h_MM2_minus->Draw("samehist");
    
    TLegend* leg2 = new TLegend(0.1,0.6,0.30,0.8);
    leg2->SetHeader("MM^2 for:");
    leg2->AddEntry(h_MM2_plus,"EB_plus solution","f");
    leg2->AddEntry(h_MM2_minus,"EB_minus solution","f");
    
    
    leg2->Draw();
    */
    
    //------------------------------------------------------------------------------------------------
    


    
    return ;
}

