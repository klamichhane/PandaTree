#ifndef PandaTree_Objects_ParticleM_h
#define PandaTree_Objects_ParticleM_h
#include "Constants.h"
#include "ParticleP.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class ParticleM : public ParticleP {
  public:
    struct datastore : public ParticleP::datastore {
      datastore() : ParticleP::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      Float_t* mass_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<ParticleM> array_type;
    typedef Collection<ParticleM> collection_type;

    typedef ParticleP base_type;

    ParticleM(char const* name = "");
    ParticleM(ParticleM const&);
    ParticleM(datastore&, UInt_t idx);
    ~ParticleM();
    ParticleM& operator=(ParticleM const&);

    double m() const override { return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m);
    void setXYZE(double px, double py, double pz, double e) override;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */
    Float_t& mass_;

  public:
    /* BEGIN CUSTOM ParticleM.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    ParticleM(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef ParticleM::array_type ParticleMArray;
  typedef ParticleM::collection_type ParticleMCollection;
  typedef Ref<ParticleM> ParticleMRef;
  typedef RefVector<ParticleM> ParticleMRefVector;

  /* BEGIN CUSTOM ParticleM.h.global */
  /* END CUSTOM */

}

#endif
