class Title extends HTMLElement {

   connectedCallback(){
       this.render();
   }
 
   render() {
       this.innerHTML = `
        <h2>Movie Lovers</h2>
        `
       
   }
}
 
customElements.define("app-bar", Title);