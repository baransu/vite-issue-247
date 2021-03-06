%raw
"import './App.css'";

[@bs.module "./logo.svg"] external logo: string = "default";

[@react.component]
let make = () => {
  let (count, setCount) = React.useState(() => 0);

  let countJson = Json.Encode.int(count);
  Js.log2("Count JSON", countJson);

  <div className="App">
    <header className="App-header">
      <img src=logo className="App-logo" alt="logo" />
      <p> {React.string("Hello Vite + Reason React")} </p>
      <p>
        <button
          className={Cn.make([
            "App-button",
            Cn.ifTrue("App-button-active", count > 10),
          ])}
          onClick={_ => setCount(_ => count + 1)}>
          {React.string("count is: " ++ string_of_int(count))}
        </button>
      </p>
      <p>
        {React.string("Edit ")}
        <code> {React.string("App.jsx ")} </code>
        {React.string("and save to test HMR updates.")}
      </p>
      <a
        className="App-link"
        href="https://reasonml.github.io/reason-react/"
        target="_blank"
        rel="noopener noreferrer">
        {React.string("Learn Reason React")}
      </a>
    </header>
  </div>;
};
