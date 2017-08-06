/*
 * Miles Lucas
 * Phys 322L Spring 2017
 * mdlucas@iastate.edu
 */

#include <string>

using namespace std;

/* These are the variables from the monte carlo simulations */
double N_ztt = 71393;
double cs_ztt = 13.3;

double N_gamma = 199990;
double cs_gamma = 5.51;

double N_ww = 101792;
double cs_ww = 0.69;

double N_tt = 101339;
double cs_tt = 0.4;

double L = 108.3;
double eff_id = 0.755;
double branch_ratio = 0.0620;

void simulation(bool save_fig=false)
{
	/* Open up data file*/
	TFile *ztt_f = new TFile("data/emu_zttllcxxx_is722.root");
	TFile *gamma_f = new TFile("data/emu_dyemxmg25_py560.root");
	TFile *ww_f = new TFile("data/emu_wwllcxxxx_py057.root");
	TFile *tt_f = new TFile("data/emu_ttll170xs_hw05.root");

	/* Get Trees */
	TTree *ztt = (TTree *)ztt_f->Get("h10");
	TTree *gamma = (TTree *)gamma_f->Get("h10");
	TTree *ww = (TTree *)ww_f->Get("h10");
	TTree *tt = (TTree *)tt_f->Get("h10");


	/* Set up canvas */
	TCanvas *c1 = new TCanvas("c", "Simulation Hists", 1000, 1000);

	gStyle->SetOptStat(111111);     // Show all statistics
	c1->Divide(2, 2);               // two columns, two rows

	/* Set up the labels for the histograms */
	TPaveText *ztt_l = new TPaveText();
	ztt_l->AddText("Z->TT");
	TPaveText *gamma_l = new TPaveText();
	gamma_l->AddText("Gamma");
	TPaveText *ww_l = new TPaveText();
	ww_l->AddText("WW");
	TPaveText *tt_l = new TPaveText();
	tt_l->AddText("tt");


	/* Define variable to check */
	const char *var = "ete1";

	/* Define Cuts */
	TCut basic_cut = "ete1 < 50";
	TCut combined_cut = "(ete1 < 50) && (memu >= 11) && (etj2 = 0)";

	/* Draw histograms */
	c1->cd(1);                      // Change the current canvas
	ztt->Draw(var, basic_cut);      // Draw the histogram for the variable with the cut
	ztt_l->Draw();                  // Draw the label for the histogram title

	c1->cd(2);
	gamma->Draw(var, basic_cut);
	gamma_l->Draw();

	c1->cd(3);
	ww->Draw(var, basic_cut);
	ww_l->Draw();

	c1->cd(4);
	tt->Draw(var, basic_cut);
	tt_l->Draw();

	/* Save the figure */
	if (save_fig) {
		system("mkdir figs"); // Make figs directory if it does not already exist
		const char *filename = "figs/your_filename_here.eps";
		c1->Print(filename);
	}

	/* Print out ratio information */
	int n_ztt = ztt->GetEntries(basic_cut);
	int n_gamma = gamma->GetEntries(basic_cut);
	int n_ww = ww->GetEntries(basic_cut);
	int n_tt = tt->GetEntries(basic_cut);

	// Get the efficiency (sig/total)
	double eff_ztt = n_ztt / N_ztt;
	double eff_gamma = n_gamma / N_gamma;
	double eff_ww = n_ww / N_ww;
	double eff_tt = n_tt / N_tt;

	// Get the expected values (luminosity * cross section * efficiency)
	double exp_ztt = eff_ztt * cs_ztt * L;
	double exp_gamma = eff_gamma * cs_gamma * L;
	double exp_ww = eff_ww * cs_ww * L;
	double exp_tt = eff_tt * cs_tt * L;

	double ratio = exp_ztt / TMath::Sqrt(exp_tt + exp_gamma + exp_ww + exp_tt);

	cout << endl <<
	"Entries\nZTT: " << n_ztt << " Gamma: " << n_gamma <<
	" WW: " << n_ww << " TT: " << n_tt << endl << endl;

	cout << "Efficiencies\nZTT: " << eff_ztt << " Gamma: " << eff_gamma <<
	" WW: " << eff_ww << " TT: " << eff_tt << endl << endl;

	cout << "Expected\nZTT: " << exp_ztt << " Gamma: " << exp_gamma <<
	" WW: " << exp_ww << " TT: " << exp_tt << endl << endl;

	cout << "Final Ratio\n" << ratio << endl;




	/* Prints out cross section. DO NOT USE TO REFINE CUTS */
	// TFile *data_f = new TFile("data/emu_data.root");
	// TTree *data = (TTree *)data_f->Get("h10");
	// int count = data->GetEntries(basic_cut);
  //
	// // Correct count for identification efficiency
	// count /= eff_id;
  //
	// double cs = (double(count) - (exp_gamma + exp_ww + exp_tt)) / (eff_ztt * L);
  //
	// cout << "emu cross section: " << cs << endl;
	// cout << "Z->TT cross section: " << cs / branch_ratio << endl;

}
